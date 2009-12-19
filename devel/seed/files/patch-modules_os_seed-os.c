--- modules/os/seed-os.c.orig	2009-10-07 01:43:54.000000000 -0400
+++ modules/os/seed-os.c	2009-12-19 14:53:48.000000000 -0500
@@ -29,8 +29,15 @@
 
 #include <sys/stat.h>
 #include <sys/utsname.h>
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#endif
 
 #include <sys/types.h>
+#include <sys/ioctl.h>
+#include <termios.h>
+#include <libutil.h>
+#include <unistd.h>
 
 #include <fcntl.h>
 
@@ -54,18 +61,32 @@ seed_os_realpath (SeedContext ctx,
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
@@ -559,7 +580,12 @@ seed_os_unsetenv (SeedContext ctx,
     }
 
   arg = seed_value_to_string (ctx, arguments[0], exception);
+#if __FreeBSD_version < 700000
+  ret = 0;
+  unsetenv (arg);
+#else
   ret = unsetenv (arg);
+#endif
   g_free (arg);
 
   return seed_value_from_int (ctx, ret, exception);
@@ -702,6 +728,7 @@ seed_os_fdatasync (SeedContext ctx,
 		   const SeedValue arguments[],
 		   SeedException * exception)
 {
+#if !defined(__FreeBSD__)
   gint fd;
 
   if (argument_count != 1)
@@ -711,6 +738,10 @@ seed_os_fdatasync (SeedContext ctx,
   fd = seed_value_to_int (ctx, arguments[0], exception);
 
   return seed_value_from_int (ctx, fdatasync (fd), exception);
+#else
+  errno = ENOSYS;
+  return seed_value_from_int (ctx, -1, exception);
+#endif
 }
 
 SeedValue
@@ -1112,7 +1143,9 @@ seed_module_init(SeedEngine * eng)
 #if defined (O_DIRECT)
   OS_DEFINE_QUICK_ENUM (O_DIRECT);
 #endif
+#if defined (O_DIRECTORY)
   OS_DEFINE_QUICK_ENUM (O_DIRECTORY);
+#endif
   OS_DEFINE_QUICK_ENUM (O_NOFOLLOW);
 #if defined (O_NOATIME)
   OS_DEFINE_QUICK_ENUM (O_NOATIME);
