--- handwriting/zinnia_handwriting.cc.orig	2013-04-21 03:48:52.166271231 +0900
+++ handwriting/zinnia_handwriting.cc	2013-04-21 04:20:14.073270179 +0900
@@ -49,10 +49,16 @@
   const char kModelFile[] = "handwriting-light-ja.model";
   return FileUtil::JoinPath(MacUtil::GetResourcesDirectory(), kModelFile);
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
   return FileUtil::JoinPath(SystemUtil::GetServerDirectory(), kModelFile);
