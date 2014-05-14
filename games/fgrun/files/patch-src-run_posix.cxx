--- src/run_posix.cxx.orig	2014-05-12 04:32:03.000000000 +0800
+++ src/run_posix.cxx	2014-05-12 04:32:24.000000000 +0800
@@ -60,7 +60,7 @@
 #if defined(HAVE_TERMIOS_H)
     struct termios term;
     tcgetattr( STDOUT_FILENO, &term );
-    term.c_oflag &= ~( OLCUC | ONLCR );
+    term.c_oflag &= ~ONLCR;
 
     pid = pty_fork( &master, 0, &term, 0 );
 #else
