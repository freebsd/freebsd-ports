--- gdb/config/i386/tm-fbsd.h	Sat Jul 28 10:03:38 2001
+++ gdb/config/i386/tm-fbsd.h	Fri Jun  7 08:32:14 2002
@@ -41,38 +45,42 @@
 /* Support for longjmp.  */
 
 /* Details about jmp_buf.  It's supposed to be an array of integers.  */
-
-#define JB_ELEMENT_SIZE 4	/* Size of elements in jmp_buf.  */
-#define JB_PC		0	/* Array index of saved PC.  */
-
-/* Figure out where the longjmp will land.  Store the address that
-   longjmp will jump to in *ADDR, and return non-zero if successful.  */
-
 #define GET_LONGJMP_TARGET(addr) get_longjmp_target (addr)
-extern int get_longjmp_target (CORE_ADDR *addr);
 
 
-/* Support for signal handlers.  */
+/* On FreeBSD, sigtramp has size 0x18 and is immediately below the
+   ps_strings struct which has size 0x10 and is at the top of the
+   user stack.  */
+
+#undef SIGTRAMP_START
+#undef SIGTRAMP_END
+#define SIGTRAMP_START(pc)    0xbfbfdfd8
+#define SIGTRAMP_END(pc)      0xbfbfdff0
 
-#define IN_SIGTRAMP(pc, name) i386bsd_in_sigtramp (pc, name)
-extern int i386bsd_in_sigtramp (CORE_ADDR pc, char *name);
-
-/* These defines allow the recognition of sigtramps as a function name
-   <sigtramp>.
-
-   FIXME: kettenis/2001-07-13: These should be added to the target
-   vector and turned into functions when we go "multi-arch".  */
-
-#define SIGTRAMP_START(pc) i386bsd_sigtramp_start
-#define SIGTRAMP_END(pc) i386bsd_sigtramp_end
 extern CORE_ADDR i386bsd_sigtramp_start;
 extern CORE_ADDR i386bsd_sigtramp_end;
+extern CORE_ADDR fbsd_kern_frame_saved_pc(struct frame_info *fr);
 
 /* Override FRAME_SAVED_PC to enable the recognition of signal handlers.  */
 
 #undef FRAME_SAVED_PC
-#define FRAME_SAVED_PC(frame) i386bsd_frame_saved_pc (frame)
-extern CORE_ADDR i386bsd_frame_saved_pc (struct frame_info *frame);
+#if __FreeBSD_version >= 500032
+#define FRAME_SAVED_PC(FRAME) \
+  (kernel_debugging ? fbsd_kern_frame_saved_pc(FRAME) : \
+  (((FRAME)->signal_handler_caller \
+    ? sigtramp_saved_pc (FRAME) \
+    : read_memory_integer ((FRAME)->frame + 4, 4)) \
+   ))
+#else
+#define FRAME_SAVED_PC(FRAME) \
+  (((FRAME)->signal_handler_caller \
+    ? sigtramp_saved_pc (FRAME) \
+    : read_memory_integer ((FRAME)->frame + 4, 4)) \
+   )
+#endif
+
+/* Offset to saved PC in sigcontext, from <sys/signal.h>.  */
+#define SIGCONTEXT_PC_OFFSET 20
 
 
 /* Shared library support.  */
