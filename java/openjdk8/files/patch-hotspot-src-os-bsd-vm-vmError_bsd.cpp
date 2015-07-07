--- hotspot/src/os/bsd/vm/vmError_bsd.cpp.orig
+++ hotspot/src/os/bsd/vm/vmError_bsd.cpp
@@ -33,30 +33,50 @@
 #include <sys/syscall.h>
 #include <unistd.h>
 #include <signal.h>
+#ifdef __FreeBSD__
+#include <limits.h>
+#include <sys/sysctl.h>
+#endif
+
+#define GDB_CMD "gdb"
+
+static void set_debugger(char *buf, int buflen) {
+  int pid = os::current_process_id();
+#ifdef __FreeBSD__
+  char cmd[PATH_MAX+1];
+  int name[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, pid };
+  size_t len = sizeof(cmd);
+  if (sysctl(name, 4, cmd, &len, NULL, 0) == 0 && len > 0) {
+    cmd[len] = '\0';
+    jio_snprintf(buf, buflen, "%s %s %d", GDB_CMD, cmd, pid);
+  } else
+#endif
+  jio_snprintf(buf, buflen, "%s /proc/%d/file %d", GDB_CMD, pid, pid);
+}
 
 void VMError::show_message_box(char *buf, int buflen) {
   bool yes;
   do {
-    error_string(buf, buflen);
-    int len = (int)strlen(buf);
+    intx tid = os::current_thread_id();
+    set_debugger(buf, buflen);
+    int len = (int)strlen(buf) + 1;
+    char *msg = &buf[len];
+    error_string(msg, buflen - len);
+    len += (int)strlen(msg);
     char *p = &buf[len];
 
     jio_snprintf(p, buflen - len,
                "\n\n"
                "Do you want to debug the problem?\n\n"
-               "To debug, run 'gdb /proc/%d/file %d'; then switch to thread " INTX_FORMAT " (" INTPTR_FORMAT ")\n"
-               "Enter 'yes' to launch gdb automatically (PATH must include gdb)\n"
+               "To debug, run '%s'; then switch to thread " INTX_FORMAT " (" INTPTR_FORMAT ")\n"
+               "Enter 'yes' to launch " GDB_CMD " automatically (PATH must include " GDB_CMD ")\n"
                "Otherwise, press RETURN to abort...",
-               os::current_process_id(), os::current_process_id(),
-               os::current_thread_id(), os::current_thread_id());
+               buf, tid, tid);
 
-    yes = os::message_box("Unexpected Error", buf);
+    yes = os::message_box("Unexpected Error", msg);
 
     if (yes) {
       // yes, user asked VM to launch debugger
-      jio_snprintf(buf, buflen, "gdb /proc/%d/file %d",
-                   os::current_process_id(), os::current_process_id());
-
       os::fork_and_exec(buf);
       yes = false;
     }
