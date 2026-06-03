--- server/util.c.orig	2025-05-04 20:53:05 UTC
+++ server/util.c
@@ -173,8 +173,12 @@ static int usleep(huge microSeconds) {
 /*
  * Hack -- External functions
  */
+#ifdef __FreeBSD__
+ #include <pwd.h>
+#else
 extern struct passwd *getpwuid (__uid_t __uid);
 extern struct passwd *getpwnam (const char *__name) __nonnull ((1));
+#endif
 
 /*
  * Find a default user name from the system.
