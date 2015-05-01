--- lxsys.c.orig	2014-11-04 10:25:00 UTC
+++ lxsys.c
@@ -63,7 +63,7 @@ int open_USB2LPT(void);
 
 struct termios old_options;
 #ifdef BSD
-char serport_name[]="/dev/ttyd....";
+char serport_name[]="/dev/ttyu....";
 #else
 char serport_name[]="/dev/ttyS....?";
 #endif
@@ -120,9 +120,9 @@ char *fmmx=" mmx";
 char *fsse=" sse";
 char *fht=" ht";
 char *fprocessor="processor";
+int no_of_ht;
 #endif
 int xxprint;
-int no_of_ht;
 // If there is no mmx, do not use simd either.
 tickspersec = sysconf(_SC_CLK_TCK);
 xxprint=0;
