--- source/ircflush.c	Sun Dec  9 04:35:25 2001
+++ source/ircflush.c	Thu Mar 15 21:57:14 2007
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
