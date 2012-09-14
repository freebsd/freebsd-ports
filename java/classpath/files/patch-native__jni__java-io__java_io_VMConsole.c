--- native/jni/java-io/java_io_VMConsole.c.orig	2012-01-08 07:35:53.000000000 -0500
+++ native/jni/java-io/java_io_VMConsole.c	2012-09-13 17:35:29.000000000 -0400
@@ -47,7 +47,7 @@
 
 /*************************************************************************/
 
-#define TERMIOS_ECHO_IFLAGS (IUCLC|IXON|IXOFF|IXANY)
+#define TERMIOS_ECHO_IFLAGS (IXON|IXOFF|IXANY)
 #define TERMIOS_ECHO_LFLAGS (ECHO|ECHOE|ECHOK|ECHONL|TOSTOP)
 
 /*
@@ -78,6 +78,9 @@
   tcgetattr (STDIN_FILENO, &new);
 
   new.c_iflag &= ~TERMIOS_ECHO_IFLAGS;
+#ifdef IUCLC
+  new.c_iflag &= ~IUCLC;
+#endif
   new.c_lflag &= ~TERMIOS_ECHO_LFLAGS;
 
   tcsetattr (STDIN_FILENO, TCSANOW, &new);
