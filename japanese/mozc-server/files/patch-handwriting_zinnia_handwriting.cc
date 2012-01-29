--- handwriting/zinnia_handwriting.cc.orig	2012-01-29 13:42:31.214806556 +0900
+++ handwriting/zinnia_handwriting.cc	2012-01-29 13:49:21.926806405 +0900
@@ -49,10 +49,16 @@
   const char kModelFile[] = "handwriting-light-ja.model";
   return Util::JoinPath(MacUtil::GetResourcesDirectory(), kModelFile);
 #elif defined(USE_LIBZINNIA)
+#if defined(__FreeBSD__)
+  const char kModelFile[] =
+      "@@LOCALBASE@@/share/tegaki/models/zinnia/handwriting-ja.model";
+  return kModelFile;
+#else
   // On Linux, use the model for tegaki-zinnia.
   const char kModelFile[] =
       "/usr/share/tegaki/models/zinnia/handwriting-ja.model";
   return kModelFile;
+#endif
 #else
   const char kModelFile[] = "handwriting-ja.model";
   return Util::JoinPath(Util::GetServerDirectory(), kModelFile);
