--- src/pl-fli.c.orig	2026-06-16 17:23:46 UTC
+++ src/pl-fli.c
@@ -5066,7 +5066,7 @@ PL_dispatch_hook(PL_dispatch_hook_t hook)
 
 
 #if defined(HAVE_SELECT) && !defined(__WINDOWS__)
-#if defined(HAVE_POLL_H) && defined(HAVE_POLL)
+#if defined(HAVE_POLL)
 #include <poll.h>
 #elif defined(HAVE_SYS_SELECT_H)
 #include <sys/select.h>
