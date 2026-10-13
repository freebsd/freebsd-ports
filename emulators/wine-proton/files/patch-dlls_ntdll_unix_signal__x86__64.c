--- dlls/ntdll/unix/signal_x86_64.c.orig	2026-08-03 08:08:29 UTC
+++ dlls/ntdll/unix/signal_x86_64.c
@@ -207,6 +207,7 @@ __ASM_GLOBAL_FUNC( modify_ldt,
 
 #elif defined(__FreeBSD__) || defined (__FreeBSD_kernel__)
 
+#include <machine/segments.h>
 #include <machine/trap.h>
 
 #define RAX_sig(context)     ((context)->uc_mcontext.mc_rax)
@@ -1832,7 +1833,7 @@ __ASM_GLOBAL_FUNC( call_user_mode_callback,
                    "1:\tmovq %rdi,%rsp\n\t"    /* user_rsp */
                    "movq 0x98(%r14),%rbp\n\t"  /* prev_frame->rbp */
                    "ldmxcsr 0xd8(%r14)\n\t"    /* prev_frame->xsave.MxCsr */
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
                    "movw 0x338(%r13),%ax\n"    /* amd64_thread_data()->fs */
                    "testw %ax,%ax\n\t"
                    "jz 1f\n\t"
@@ -3038,6 +3039,16 @@ void ldt_set_entry( WORD sel, LDT_ENTRY entry )
     if ((ret = modify_ldt( &ldt_info ))) ERR( "modify_ldt failed %d\n", ret );
 #elif defined(__APPLE__)
     if (i386_set_ldt(sel >> 3, (union ldt_entry *)&entry, 1) < 0) perror("i386_set_ldt");
+#elif defined(__FreeBSD__)
+    struct i386_ldt_args p;
+    p.start = sel >> 3;
+    p.descs = (struct user_segment_descriptor *)&entry;
+    p.num   = 1;
+    if (sysarch(I386_SET_LDT, &p) == -1)
+    {
+        perror("i386_set_ldt");
+        exit(1);
+    }
 #else
     fprintf( stderr, "No LDT support on this platform\n" );
     exit(1);
@@ -3159,6 +3170,8 @@ void signal_init_process(void)
         fs32_sel = alloc_fs_sel( -1, wow_teb );
 #elif defined(__APPLE__)
         cs32_sel = ldt_alloc_entry( ldt_make_cs32_entry() );
+#elif defined(__FreeBSD__)
+        cs32_sel = GSEL(GUCODE32_SEL, SEL_UPL);
 #endif
     }
 
@@ -3197,7 +3210,11 @@ void set_thread_teb( TEB *teb )
 
 void set_thread_teb( TEB *teb )
 {
+#if defined __linux__
     arch_prctl( ARCH_SET_GS, teb );
+#elif defined (__FreeBSD__)
+    amd64_set_gsbase( teb );
+#endif
 }
 
 /***********************************************************************
@@ -3223,6 +3240,7 @@ void init_syscall_frame( LPTHREAD_START_ROUTINE entry,
     }
 #elif defined (__FreeBSD__) || defined (__FreeBSD_kernel__)
     amd64_set_gsbase( teb );
+    amd64_get_fsbase( &thread_data->pthread_teb );
 #elif defined(__NetBSD__)
     sysarch( X86_64_SET_GSBASE, &teb );
 #elif defined (__APPLE__)
@@ -3448,6 +3466,28 @@ __ASM_GLOBAL_FUNC( __wine_syscall_dispatcher,
                    "syscall\n\t"
                    "leaq -0x98(%rbp),%rcx\n"
                    "2:\n\t"
+#elif defined(__FreeBSD__)
+                   "movq 0x320(%r13),%rsi\n\t"     /* amd64_thread_data()->pthread_teb */
+                   "testq %rsi,%rsi\n\t"
+                   "jz 2f\n\t"
+                   "cmpb $0,0x7ffe028a\n\t"        /* user_shared_data->ProcessorFeatures[PF_RDWRFSGSBASE_AVAILABLE] */
+                   "jz 1f\n\t"
+                   "wrfsbase %rsi\n\t"
+                   "jmp 2f\n"
+                   "1:\n\t"
+                   "pushq %r8\n\t"
+                   "pushq %r9\n\t"
+                   "pushq %r10\n\t"
+                   "pushq %r11\n\t"
+                   "movq $0xa5,%rax\n\t"           /* sysarch */
+                   "movq $0x81,%rdi\n\t"           /* AMD64_SET_FSBASE */
+                   "syscall\n\t"
+                   "popq %r11\n\t"
+                   "popq %r10\n\t"
+                   "popq %r9\n\t"
+                   "popq %r8\n\t"
+                   "leaq -0x98(%rbp),%rcx\n"
+                   "2:\n\t"
 #elif defined __APPLE__
                    "movq 0x320(%r13),%rdi\n\t"     /* amd64_thread_data()->pthread_teb */
                    "xorl %esi,%esi\n\t"
@@ -3494,11 +3534,16 @@ __ASM_GLOBAL_FUNC( __wine_syscall_dispatcher,
                    __ASM_CFI(".cfi_remember_state\n\t")
                    __ASM_CFI_CFA_IS_AT2(rcx, 0xa8, 0x01) /* frame->syscall_cfa */
                    "leaq 0x70(%rcx),%rsp\n\t"      /* %rsp > frame means no longer inside syscall */
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
                    "movw 0x338(%r13),%dx\n"        /* amd64_thread_data()->fs */
                    "testw %dx,%dx\n\t"
                    "jz 1f\n\t"
                    "movw %dx,%fs\n"
+# ifdef __FreeBSD__
+                   /* reset %ss (after sysret) for AMD */
+                   "movw $0x3b,%dx\n\t"           /* GSEL(GUDATA_SEL, SEL_UPL) */
+                   "movw %dx,%ss\n\t"
+# endif
                    "1:\n\t"
 #elif defined __APPLE__
                    "movq %rax,%r8\n\t"
@@ -3736,6 +3781,27 @@ __ASM_GLOBAL_FUNC( __wine_unix_call_dispatcher,
                    "mov $158,%eax\n\t"             /* SYS_arch_prctl */
                    "syscall\n\t"
                    "2:\n\t"
+#elif defined(__FreeBSD__)
+                   "movq 0x320(%r13),%rsi\n\t"     /* amd64_thread_data()->pthread_teb */
+                   "testq %rsi,%rsi\n\t"
+                   "jz 2f\n\t"
+                   "cmpb $0,0x7ffe028a\n\t"        /* user_shared_data->ProcessorFeatures[PF_RDWRFSGSBASE_AVAILABLE] */
+                   "jz 1f\n\t"
+                   "wrfsbase %rsi\n\t"
+                   "jmp 2f\n"
+                   "1:\n\t"
+                   "pushq %r8\n\t"
+                   "pushq %r9\n\t"
+                   "pushq %r10\n\t"
+                   "pushq %r11\n\t"
+                   "movq $0xa5,%rax\n\t"           /* sysarch */
+                   "movq $0x81,%rdi\n\t"           /* AMD64_SET_FSBASE */
+                   "syscall\n\t"
+                   "popq %r11\n\t"
+                   "popq %r10\n\t"
+                   "popq %r9\n\t"
+                   "popq %r8\n\t"
+                   "2:\n\t"
 #elif defined __APPLE__
                    "movq 0x320(%r13),%rdi\n\t"     /* amd64_thread_data()->pthread_teb */
                    "xorl %esi,%esi\n\t"
@@ -3762,11 +3828,16 @@ __ASM_GLOBAL_FUNC( __wine_unix_call_dispatcher,
                    /* switch to user stack */
                    "movq 0x88(%rcx),%rsp\n\t"
                    __ASM_CFI(".cfi_restore_state\n\t")
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
                    "movw 0x338(%r13),%dx\n"        /* amd64_thread_data()->fs */
                    "testw %dx,%dx\n\t"
                    "jz 1f\n\t"
                    "movw %dx,%fs\n"
+# ifdef __FreeBSD__
+                   /* reset %ss (after sysret) for AMD */
+                   "movw $0x3b,%dx\n\t"           /* GSEL(GUDATA_SEL, SEL_UPL) */
+                   "movw %dx,%ss\n\t"
+# endif
                    "1:\n\t"
 #elif defined __APPLE__
                    "movq %rax,%rdx\n\t"
