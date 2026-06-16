--- src/os/pl-stream.c.orig	2026-06-16 17:23:46 UTC
+++ src/os/pl-stream.c
@@ -98,7 +98,7 @@ - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 #include <stdarg.h>
 #include <ctype.h>
 #include <sys/stat.h>
-#if defined(HAVE_POLL_H)
+#if defined(HAVE_POLL)
 #include <poll.h>
 #elif defined(HAVE_SYS_SELECT_H)
 #include <sys/select.h>
