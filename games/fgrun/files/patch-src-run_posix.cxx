--- src/run_posix.cxx.orig	2009-01-25 17:01:58.000000000 +0000
+++ src/run_posix.cxx	2009-03-09 01:08:38.080801315 +0000
@@ -59,7 +59,7 @@
 #if defined(HAVE_TERMIOS_H)
     struct termios term;
     tcgetattr( STDOUT_FILENO, &term );
-    term.c_oflag &= ~( OLCUC | ONLCR );
+    term.c_oflag &= ~ONLCR;
 
     pid = pty_fork( &master, 0, &term, 0 );
 #else
@@ -171,7 +171,7 @@
 #if defined(HAVE_TERMIOS_H)
     struct termios term;
     tcgetattr( STDOUT_FILENO, &term );
-    term.c_oflag &= ~( OLCUC | ONLCR );
+    term.c_oflag &= ~ONLCR;
 
     tsPid = pty_fork( &master, 0, &term, 0 );
 #else
