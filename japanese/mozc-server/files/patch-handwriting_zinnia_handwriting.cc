--- handwriting/zinnia_handwriting.cc.orig	2012-04-02 08:17:52.785727643 +0900
+++ handwriting/zinnia_handwriting.cc	2012-04-02 08:38:43.657727715 +0900
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
