--- timer.c.orig	1995-12-22 12:08:21 UTC
+++ timer.c
@@ -85,7 +85,7 @@
       sigprocmask(SIG_BLOCK, &temp, (maskp)); \
     }
 #  define signal_release(maskp) sigprocmask(SIG_SETMASK, maskp, (MASK *)NULL)
-#  define signal_pause(maskp) sigpause(*(maskp))
+#  define signal_pause(maskp) sigsuspend(maskp)
 #else
 #  ifdef __hpux /* hpux is a weird mixture of BSD & SYSV */
 /* don't know if this is right */
