Adding the following patch to the files/ directory removes the unneeded
inclusion.

--- source/ircflush.c	Fri Jan  6 16:16:45 1995
+++ source/ircflush.c	Mon Jun  4 09:38:12 2007
@@ -12,15 +12,6 @@
 #include "irc.h"
 #include <sys/wait.h>
 
-#ifndef __linux__
-# ifdef __svr4__
-#  include <sys/termios.h>
-# else
-#  include <sgtty.h>	/* SVR4 => sgtty = yuk */
-# endif /* SOLARIS */
-#endif /* __linux__ */
-
-
 #define BUFFER_SIZE 1024
 
 /* descriptors of the tty and pty */
