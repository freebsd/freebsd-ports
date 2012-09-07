--- handwriting/zinnia_handwriting.cc.orig	2012-09-07 10:21:29.209021370 +0900
+++ handwriting/zinnia_handwriting.cc	2012-09-07 10:38:01.976021756 +0900
@@ -50,10 +50,16 @@
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
