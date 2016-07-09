--- library/tulip-core/src/PluginLibraryLoader.cpp.orig	2016-07-07 20:15:54 UTC
+++ library/tulip-core/src/PluginLibraryLoader.cpp
@@ -138,7 +138,14 @@ bool PluginLibraryLoader::loadPluginLibr
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
