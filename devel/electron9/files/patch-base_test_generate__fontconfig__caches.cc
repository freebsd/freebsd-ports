--- base/test/generate_fontconfig_caches.cc.orig	2020-05-26 08:03:15 UTC
+++ base/test/generate_fontconfig_caches.cc
@@ -59,7 +59,14 @@ int main() {
   FcFini();
 
   // Check existence of intended fontconfig cache file.
+#if defined(OS_BSD)
+  // Our version of fontconfig is too old to respect .uuid files in font directories,
+  // so we check for the CACHEDIR.TAG file instead
   CHECK(base::PathExists(
+      fontconfig_caches.Append("CACHEDIR.TAG")));
+#else
+  CHECK(base::PathExists(
       fontconfig_caches.Append(base::StrCat({uuid, "-le64.cache-7"}))));
+#endif
   return 0;
 }
