--- src/ripper_encoder_manipulation.c.orig	2008-02-02 18:51:29.000000000 +0100
+++ src/ripper_encoder_manipulation.c	2008-02-22 16:15:16.000000000 +0100
@@ -16,7 +16,6 @@
 #include <fcntl.h>
 #include <sys/wait.h>
 #include <sys/ioctl.h>
-#include <pty.h>
 
 #include "ripper_encoder_manipulation.h"
 #include "misc_utils.h"
@@ -335,7 +334,7 @@
 		dup2( pty_fd0, 0 );
 		dup2( tty_fd1, 1 );
 
-		setpgrp();
+		setpgid(0, 0);
 		execvp( plugin_argv[ 0 ], plugin_argv );
 
 		dup2( stderr_fd, 2 );
@@ -368,7 +367,7 @@
 		dup2( tty_fd0, 1 );
 		dup2( tty_fd0, 2 );
 
-		setpgrp();
+		setpgid(0, 0);
 		execvp( program_argv[ 0 ], program_argv );
 
 		dup2( stderr_fd, 2 );
