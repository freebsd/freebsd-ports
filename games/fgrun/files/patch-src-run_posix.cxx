--- src/run_posix.cxx.orig	2008-04-23 04:51:01.000000000 +0800
+++ src/run_posix.cxx	2008-10-18 17:28:27.000000000 +0800
@@ -58,7 +58,7 @@
 #if defined(HAVE_TERMIOS_H)
     struct termios term;
     tcgetattr( STDOUT_FILENO, &term );
-    term.c_oflag &= ~( OLCUC | ONLCR );
+    term.c_oflag &= ~ONLCR;
 
     pid = pty_fork( &master, 0, &term, 0 );
 #else
