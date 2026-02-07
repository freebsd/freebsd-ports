--- textio/textioInt.h.orig	2025-07-30 06:00:02 UTC
+++ textio/textioInt.h
@@ -43,7 +43,7 @@ typedef struct {
 #define TX_CMD_PROMPT	":"
 
 /* all of the state associated with a tty terminal */
-#if !defined(SYSV) && !defined(CYGWIN) && !defined(__OpenBSD__) && !defined(EMSCRIPTEN)
+#if !defined(SYSV) && !defined(CYGWIN) && !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(EMSCRIPTEN)
 #if defined(HAVE_SYS_IOCTL_COMPAT_H) || defined(HAVE_SGTTY_H)
 #if defined(HAVE_SYS_IOCTL_COMPAT_H)
 #include <sys/ioctl_compat.h> /* replaced sgtty.h */
