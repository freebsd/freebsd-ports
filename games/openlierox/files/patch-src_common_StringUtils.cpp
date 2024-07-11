--- src/common/StringUtils.cpp.orig	2018-02-01 15:56:41 UTC
+++ src/common/StringUtils.cpp
@@ -751,7 +751,11 @@ static void charactersParsed(void* context, const xmlC
 }
 
 /* GCS: custom error function to ignore errors */
+#if LIBXML_VERSION >= 21300
+static void xmlErrorHandlerDummy(void *, const xmlError *)
+#else
 static void xmlErrorHandlerDummy(void *, xmlErrorPtr)
+#endif
 {
 	/* ignore all errors */
 }
