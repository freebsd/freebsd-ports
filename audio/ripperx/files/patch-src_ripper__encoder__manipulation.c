--- src/ripper_encoder_manipulation.c.orig	2010-11-07 05:42:25 UTC
+++ src/ripper_encoder_manipulation.c
@@ -16,7 +16,6 @@
 #include <fcntl.h>
 #include <sys/wait.h>
 #include <sys/ioctl.h>
-#include <pty.h>
 
 #include "ripper_encoder_manipulation.h"
 #include "misc_utils.h"
@@ -340,7 +339,7 @@ int execute_ripper_encoder_with_plugin( 
 		dup2( pty_fd0, 0 );
 		dup2( tty_fd1, 1 );
 
-		setpgrp();
+		setpgid(0, 0);
 		execvp( plugin_argv[ 0 ], plugin_argv );
 
 		dup2( stderr_fd, 2 );
@@ -373,7 +372,7 @@ int execute_ripper_encoder_with_plugin( 
 		dup2( tty_fd0, 1 );
 		dup2( tty_fd0, 2 );
 
-		setpgrp();
+		setpgid(0, 0);
 		execvp( program_argv[ 0 ], program_argv );
 
 		dup2( stderr_fd, 2 );
