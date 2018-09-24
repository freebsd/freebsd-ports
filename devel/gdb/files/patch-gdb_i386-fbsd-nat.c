--- gdb/i386-fbsd-nat.c 2017-09-14 09:28:17 UTC
+++ gdb/i386-fbsd-nat.c
@@ -43,8 +43,6 @@ public:
   const struct target_desc *read_description () override;
 #endif
 
-  void resume (ptid_t, int, enum gdb_signal) override;
-
 #if defined(HAVE_PT_GETDBREGS) && defined(USE_SIGTRAP_SIGINFO)
   bool supports_stopped_by_hw_breakpoint () override;
 #endif
@@ -52,6 +50,7 @@ public:
 
 static i386_fbsd_nat_target the_i386_fbsd_nat_target;
 
+#if 0
 /* Resume execution of the inferior process.  If STEP is nonzero,
    single-step it.  If SIGNAL is nonzero, give it that signal.  */
 
@@ -98,6 +97,7 @@ i386_fbsd_nat_target::resume (ptid_t ptid, int step, enum gdb_signal signal)
 	      gdb_signal_to_host (signal)) == -1)
     perror_with_name (("ptrace"));
 }
+#endif
 
 
 /* Support for debugging kernel virtual memory images.  */
