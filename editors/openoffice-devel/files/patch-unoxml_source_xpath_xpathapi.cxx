--- unoxml/source/xpath/xpathapi.cxx.orig	2019-09-17 22:55:24 UTC
+++ unoxml/source/xpath/xpathapi.cxx
@@ -267,7 +267,11 @@ namespace XPath
         return selectSingleNode(contextNode, expr);
     }
 
-    static OUString make_error_message(xmlErrorPtr pError)
+#if LIBXML_VERSION >= 21200
+    static OUString make_error_message(const xmlError *pError)
+#else
+    static OUString make_error_message(xmlError *pError)
+#endif
     {
         ::rtl::OUStringBuffer buf;
         if (pError->message) {
@@ -312,7 +316,11 @@ namespace XPath
             OSL_ENSURE(sal_False, msg.getStr());
         }
 
-        static void structured_error_func(void * userData, xmlErrorPtr error)
+#if LIBXML_VERSION >= 21200
+        static void structured_error_func(void * userData, const xmlError *error)
+#else
+        static void structured_error_func(void * userData, xmlError *error)
+#endif
         {
             (void) userData;
             ::rtl::OUStringBuffer buf(
