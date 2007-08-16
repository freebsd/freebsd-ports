--- ../../hotspot/src/os/bsd/vm/vmError_bsd.cpp	28 Mar 2007 04:52:29 -0000	1.1
+++ ../../hotspot/src/os/bsd/vm/vmError_bsd.cpp	9 Aug 2007 15:52:44 -0000	1.3
@@ -30,7 +30,7 @@
 // Unlike system(), this function can be called from signal handler. It
 // doesn't block SIGINT et al.
 int VMError::fork_and_exec(char* cmd) {
-  char * argv[4];
+  const char *argv[4];
   argv[0] = "sh";
   argv[1] = "-c";
   argv[2] = cmd;
