--- core/libs/metadataengine/engine/metaengine_p.h.orig	2023-03-12 13:19:02 UTC
+++ core/libs/metadataengine/engine/metaengine_p.h
@@ -90,6 +90,10 @@
          ( EXIV2_VERSION >= EXIV2_MAKE_VERSION(major,minor,patch) )
 #endif
 
+#if EXIV2_TEST_VERSION(0,28,0)
+#   define AnyError Error
+#endif
+
 #if EXIV2_TEST_VERSION(0,27,99)
 #   define AutoPtr UniquePtr
 #endif
@@ -182,7 +186,7 @@ class Q_DECL_HIDDEN MetaEngine::Private (public)
      * Generic method to print the Exiv2 C++ Exception error message from 'e'.
      * 'msg' string is printed using qDebug rules.
      */
-    static void printExiv2ExceptionError(const QString& msg, Exiv2::AnyError& e);
+    static void printExiv2ExceptionError(const QString& msg, Exiv2::Error& e);
 
     /**
      * Generic method to print debug message from Exiv2.
