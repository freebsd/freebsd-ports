--- gegl/gegl-init.c.orig	2025-12-11 20:43:07 UTC
+++ gegl/gegl-init.c
@@ -68,6 +68,11 @@ DllMain (HINSTANCE hinstDLL,
 #import <Foundation/Foundation.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/limits.h>
+#include <sys/param.h>
+#endif
+
 #include "gegl-debug.h"
 
 guint gegl_debug_flags = 0;
@@ -901,7 +906,11 @@ gegl_find_relocatable_exe (void)
   if (path)
     return path;
 
+#if defined(__FreeBSD__)
+  sym_path = g_strdup ("/proc/curproc/file");
+#else
   sym_path = g_strdup ("/proc/self/exe");
+#endif
 
   while (1)
     {
@@ -917,7 +926,11 @@ gegl_find_relocatable_exe (void)
           /* I don't think /proc/self/ symlinks will ever be relative, but just
            * to be safe.
            */
+#if defined(__FreeBSD__)
+          gchar *absolute_path = g_build_filename ("/proc/curproc", path, NULL);
+#else
           gchar *absolute_path = g_build_filename ("/proc/self", path, NULL);
+#endif
           g_free (path);
           path = g_steal_pointer (&absolute_path);
         }
@@ -944,8 +957,11 @@ gegl_find_relocatable_exe (void)
    * Read from /proc/self/maps as fallback.
    */
 
+#if defined(__FreeBSD__)
+  file = g_fopen ("/proc/curproc/map", "rb");
+#else
   file = g_fopen ("/proc/self/maps", "rb");
-
+#endif
   g_return_val_if_fail (file != NULL, NULL);
 
   /* The first entry with r-xp permission should be the executable name. */
@@ -955,7 +971,11 @@ gegl_find_relocatable_exe (void)
       path = strchr (maps_line, '/');
 
       /* Sanity check. */
+#if defined(__FreeBSD__)
+      if (path && strstr (maps_line, " r-x "))
+#else
       if (path && strstr (maps_line, " r-xp "))
+#endif
         {
           /* We found the executable name. */
           path = g_strdup (path);
