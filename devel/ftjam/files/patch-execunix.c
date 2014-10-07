--- execunix.c.orig	2006-06-05 12:52:27.000000000 +0200
+++ execunix.c	2014-08-07 15:38:48.000000000 +0200
@@ -45,6 +45,13 @@
 
 # ifdef USE_EXECUNIX
 
+
+# ifdef OS_FREEBSD
+# include <unistd.h>
+# include <sys/types.h>
+# include <sys/wait.h>
+# endif
+
 # ifdef OS_OS2
 # define USE_EXECNT
 # include <process.h>
@@ -85,6 +92,8 @@
 void
 onintr( int disp )
 {
+	(void)disp;
+
 	intr++;
 	printf( "...interrupted\n" );
 }
@@ -231,7 +240,7 @@
 # else
 	if ((pid = vfork()) == 0) 
    	{
-		execvp( argv[0], argv );
+		execvp( argv[0], (char * const *)argv );
 		_exit(127);
 	}
 # endif
