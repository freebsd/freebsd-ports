
$FreeBSD$

--- pal/unix/exception/signal.c	2002/03/28 19:30:03	1.1
+++ pal/unix/exception/signal.c	2002/03/28 19:33:48
@@ -31,6 +31,7 @@
 #include <signal.h>
 #include <errno.h>
 #include <string.h>
+#include <sys/ucontext.h>
 #include <sys/utsname.h>
 #include <fcntl.h>
 #include <unistd.h>
@@ -601,11 +602,13 @@
     case T_ARITHTRAP : /* arithmetic trap */
         TRACE("Trap code T_ARITHTRAP maps to floating point exception...\n");
         return 0;      /* let the caller pick an exception code */
+#ifdef T_ASTFLT
     case T_ASTFLT :    /* system forced exception : ^C, ^\. SIGINT signal 
                           handler shouldn't be calling this function, since
                           it doesn't need an exception code */
         ASSERT("Trap code T_ASTFLT received, shouldn't get here\n");
         return 0;  
+#endif
     case T_PROTFLT :   /* protection fault */
         TRACE("Trap code T_PROTFLT mapped to EXCEPTION_ACCESS_VIOLATION\n");
         return EXCEPTION_ACCESS_VIOLATION; 
