--- main.cc.orig	Fri Nov 28 16:17:58 2003
+++ main.cc	Fri Nov 28 14:44:27 2003
@@ -25,6 +25,7 @@
 #include <unistd.h>
 #include <signal.h>
 #include <regex.h>
+#include <errno.h>
 #ifdef X11
  #include <X11/Xlib.h>
 #endif
@@ -91,6 +92,8 @@
 
 /***************************************************************************/
 
+int fork2();
+
 void resetcfg(int flag,char *str)
 {
  if (config.keys==(unsigned int *)0xffffffff) config.keys=0;
@@ -554,7 +557,7 @@
 
     if (piped) pipe(pp); else deinit(); // ripristino i settaggi del terminale
 
-    if ((pid=fork())==0)
+    if ((pid=fork2())==0)
     { // figlio
      char *argv[100];
      int argc=0;
@@ -1352,6 +1355,32 @@
  deinit();
 
  return(0);
+}
+
+int fork2() {
+  pid_t pid;
+  int status;
+
+  if (!(pid = fork())) {
+    switch (fork()) {
+      case 0:  return 0;
+      case -1: _exit(errno);    /* assumes all errnos are <256 */
+      default: _exit(0);
+    }
+  }
+
+  if (pid < 0 || waitpid(pid,&status,0) < 0)
+    return -1;
+
+  if (WIFEXITED(status))
+    if (WEXITSTATUS(status) == 0)
+      return 1;
+    else
+      errno = WEXITSTATUS(status);
+  else
+    errno = EINTR;  /* well, sort of :-) */
+
+  return -1;
 }
 
 /***************************************************************************/
