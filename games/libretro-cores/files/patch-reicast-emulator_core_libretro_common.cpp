--- reicast-emulator/core/libretro/common.cpp.orig	2016-11-04 17:23:51 UTC
+++ reicast-emulator/core/libretro/common.cpp
@@ -215,7 +215,7 @@ static void context_segfault(rei_host_co
 {
 #if !defined(TARGET_NO_EXCEPTIONS)
 #if HOST_CPU == CPU_ARM
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
    bicopy(reictx->pc, MCTX(.arm_pc), to_segfault);
    u32* r =(u32*) &MCTX(.arm_r0);
 
@@ -229,11 +229,16 @@ static void context_segfault(rei_host_co
 #endif
 
 #elif HOST_CPU == CPU_X86
-#ifdef __linux__
+#if defined(__linux__)
    bicopy(reictx->pc, MCTX(.gregs[REG_EIP]), to_segfault);
    bicopy(reictx->esp, MCTX(.gregs[REG_ESP]), to_segfault);
    bicopy(reictx->eax, MCTX(.gregs[REG_EAX]), to_segfault);
    bicopy(reictx->ecx, MCTX(.gregs[REG_ECX]), to_segfault);
+#elif defined(__FreeBSD__)
+   bicopy(reictx->pc, MCTX(.mc_eip), to_segfault);
+   bicopy(reictx->esp, MCTX(.mc_esp), to_segfault);
+   bicopy(reictx->eax, MCTX(.mc_eax), to_segfault);
+   bicopy(reictx->ecx, MCTX(.mc_ecx), to_segfault);
 #elif defined(__MACH__)
    bicopy(reictx->pc, MCTX(->__ss.__eip), to_segfault);
    bicopy(reictx->esp, MCTX(->__ss.__esp), to_segfault);
@@ -241,8 +246,10 @@ static void context_segfault(rei_host_co
    bicopy(reictx->ecx, MCTX(->__ss.__ecx), to_segfault);
 #endif
 #elif HOST_CPU == CPU_X64
-#ifdef __linux__
+#if defined(__linux__)
    bicopy(reictx->pc, MCTX(.gregs[REG_RIP]), to_segfault);
+#elif defined(__FreeBSD__)
+   bicopy(reictx->pc, MCTX(.mc_rip), to_segfault);
 #elif defined(__MACH__)
    bicopy(reictx->pc, MCTX(->__ss.__rip), to_segfault);
 #endif
@@ -292,7 +299,7 @@ static void sigill_handler(int sn, sigin
 }
 #endif
 
-#if defined(__MACH__) || defined(__linux__)
+#if defined(__MACH__) || defined(__linux__) || defined(__FreeBSD__)
 //#define LOG_SIGHANDLER
 
 static void fault_handler (int sn, siginfo_t * si, void *segfault_ctx)
@@ -566,7 +573,7 @@ void common_libretro_setup(void)
    ReserveBottomMemory();
 #endif
 
-#if defined(__MACH__) || defined(__linux__)
+#if defined(__MACH__) || defined(__linux__) || defined(__FreeBSD__)
    enable_runfast();
 #endif
 #ifdef _WIN32
@@ -582,7 +589,7 @@ void common_libretro_setup(void)
 
    settings.profile.run_counts=0;
 
-#if defined(__MACH__) || defined(__linux__)
+#if defined(__MACH__) || defined(__linux__) || defined(__FreeBSD__)
    printf("Linux paging: %08X %08X %08X\n",sysconf(_SC_PAGESIZE),PAGE_SIZE,PAGE_MASK);
    verify(PAGE_MASK==(sysconf(_SC_PAGESIZE)-1));
 #endif
