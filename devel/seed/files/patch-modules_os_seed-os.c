--- modules/os/seed-os.c.orig	2009-08-10 16:23:35.000000000 -0400
+++ modules/os/seed-os.c	2009-08-22 14:43:42.000000000 -0400
@@ -31,6 +31,10 @@
 #include <sys/utsname.h>
 
 #include <sys/types.h>
+#include <sys/ioctl.h>
+#include <termios.h>
+#include <libutil.h>
+#include <unistd.h>
 
 #include <fcntl.h>
 
@@ -54,18 +58,32 @@ seed_os_realpath (SeedContext ctx,
 	          const SeedValue arguments[],
 	          SeedException * exception)
 {
+  SeedValue sv;
   gchar *arg;
+  gchar *resolved_path;
   gchar *ret;
+  gsize path_max;
 
   if (argument_count != 1)
     {
       EXPECTED_EXCEPTION("os.realpath", "1 argument");
     }
   arg = seed_value_to_string (ctx, arguments[0], exception);
-  ret = canonicalize_file_name(arg);
+#ifdef PATH_MAX
+  path_max = PATH_MAX;
+#else
+  path_max = pathconf (arg, _PC_PATH_MAX);
+  if (path_max <= 0)
+    path_max = 4096;
+#endif
+  resolved_path = (gchar *) g_malloc (path_max);
+  ret = realpath(arg, resolved_path);
   g_free (arg);
 
-  return seed_value_from_string (ctx, ret, exception);
+  sv = seed_value_from_string (ctx, ret, exception);
+  g_free (resolved_path);
+
+  return sv;
 }
 
 SeedValue
@@ -702,6 +720,7 @@ seed_os_fdatasync (SeedContext ctx,
 		   const SeedValue arguments[],
 		   SeedException * exception)
 {
+#if !defined(__FreeBSD__)
   gint fd;
 
   if (argument_count != 1)
@@ -711,6 +730,10 @@ seed_os_fdatasync (SeedContext ctx,
   fd = seed_value_to_int (ctx, arguments[0], exception);
 
   return seed_value_from_int (ctx, fdatasync (fd), exception);
+#else
+  errno = ENOSYS;
+  return seed_value_from_int (ctx, -1, exception);
+#endif
 }
 
 SeedValue
@@ -1112,7 +1135,9 @@ seed_module_init(SeedEngine * eng)
 #if defined (O_DIRECT)
   OS_DEFINE_QUICK_ENUM (O_DIRECT);
 #endif
+#if defined (O_DIRECTORY)
   OS_DEFINE_QUICK_ENUM (O_DIRECTORY);
+#endif
   OS_DEFINE_QUICK_ENUM (O_NOFOLLOW);
 #if defined (O_NOATIME)
   OS_DEFINE_QUICK_ENUM (O_NOATIME);
