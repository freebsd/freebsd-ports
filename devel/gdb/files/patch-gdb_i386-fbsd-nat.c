--- gdb/i386-fbsd-nat.c.orig	2022-05-02 12:03:48.925048000 -0700
+++ gdb/i386-fbsd-nat.c	2022-05-02 12:04:43.474983000 -0700
@@ -41,8 +41,6 @@ class i386_fbsd_nat_target final : public x86_fbsd_nat
   void store_registers (struct regcache *, int) override;
 
   const struct target_desc *read_description () override;
-
-  void resume (ptid_t, int, enum gdb_signal) override;
 };
 
 static i386_fbsd_nat_target the_i386_fbsd_nat_target;
@@ -227,6 +225,7 @@ i386_fbsd_nat_target::store_registers (struct regcache
     perror_with_name (_("Couldn't write floating point status"));
 }
 
+#if 0
 /* Resume execution of the inferior process.  If STEP is nonzero,
    single-step it.  If SIGNAL is nonzero, give it that signal.  */
 
@@ -273,6 +272,7 @@ i386_fbsd_nat_target::resume (ptid_t ptid, int step, e
 	      gdb_signal_to_host (signal)) == -1)
     perror_with_name (("ptrace"));
 }
+#endif
 
 
 /* Support for debugging kernel virtual memory images.  */
