--- library/tulip-core/src/PluginLibraryLoader.cpp.orig	2015-04-18 20:15:27 UTC
+++ library/tulip-core/src/PluginLibraryLoader.cpp
@@ -130,7 +130,14 @@ bool PluginLibraryLoader::loadPluginLibr
 }
 
 // accepts only file whose name matches *.so or *.dylib
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#if (__FreeBSD_version < 900000 && __FreeBSD_version >= 800501) || (__FreeBSD_version >= 900006)
+int __tulip_select_libs(const struct dirent *ent) {
+#else
 int __tulip_select_libs(struct dirent *ent) {
+#endif /* __FreeBSD_version */
+#endif /* __FreeBSD__ */
 #if !defined(__APPLE__)
   const char *suffix = ".so";
   const unsigned long suffix_len = 3;
