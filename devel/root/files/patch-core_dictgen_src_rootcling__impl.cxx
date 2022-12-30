--- core/dictgen/src/rootcling_impl.cxx.orig	2022-11-16 10:35:46 UTC
+++ core/dictgen/src/rootcling_impl.cxx
@@ -191,7 +191,7 @@ const char *GetExePath()
 #ifdef __APPLE__
     exepath = _dyld_get_image_name(0);
 #endif
-#if defined(__linux) || defined(__linux__)
+#if defined(__linux) || defined(__linux__) || defined(R__FBSD)
     char linkname[PATH_MAX];  // /proc/<pid>/exe
     char buf[PATH_MAX];     // exe path name
     pid_t pid;
