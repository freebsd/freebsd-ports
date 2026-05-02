--- src/extension/internal/pdfinput/poppler-utils.cpp.orig	2025-12-26 00:35:50 UTC
+++ src/extension/internal/pdfinput/poppler-utils.cpp
@@ -16,6 +16,7 @@
 #include <poppler/GfxFont.h>
 #include <poppler/GfxState.h>
 #include <poppler/PDFDoc.h>
+#include <poppler/PDFDocEncoding.h>
 #include <poppler/UTF.h>
 
 #include "libnrtype/font-factory.h"
@@ -88,7 +89,11 @@ InkFontDict::InkFontDict(XRef *xref, Ref *fontDictRef,
                 r.num = hashFontObject(&obj2);
             }
             // Newer poppler will require some reworking as it gives a shared ptr.
+#if POPPLER_CHECK_VERSION(26,3,0)
+            fonts[i] = GfxFont::makeFont(xref, fontDict->getKey(i), r, *obj2.getDict());
+#else
             fonts[i] = GfxFont::makeFont(xref, fontDict->getKey(i), r, obj2.getDict());
+#endif
             if (fonts[i] && !fonts[i]->isOk()) {
                 fonts[i] = nullptr;
             }
@@ -145,7 +150,6 @@ void InkFontDict::hashFontObject1(const Object *obj, F
 
 void InkFontDict::hashFontObject1(const Object *obj, FNVHash *h)
 {
-    const GooString *s;
     const char *p;
     double r;
     int n, i;
@@ -165,11 +169,16 @@ void InkFontDict::hashFontObject1(const Object *obj, F
             r = obj->getReal();
             h->hash((char *)&r, sizeof(double));
             break;
-        case objString:
+        case objString: {
             h->hash('s');
-            s = obj->getString();
+#if POPPLER_CHECK_VERSION(26, 4, 0)
+            const auto &s = obj->getString();
+            h->hash(s.c_str(), s.size());
+#else
+            const GooString* s = obj->getString();
             h->hash(s->c_str(), get_goostring_length(*s));
-            break;
+#endif
+            } break;
         case objName:
             h->hash('n');
             p = obj->getName();
@@ -586,20 +595,52 @@ std::string getDictString(Dict *dict, const char *key)
     return getString(obj.getString());
 }
 
+std::string getString(const std::unique_ptr<GooString> &value)
+{
+    return getString(value.get());
+}
+
+std::string getString(const GooString *value)
+{
+    if (value) {
+        return getString(value->toStr());
+    }
+    return "";
+}
+
 /**
  * Convert PDF strings, which can be formatted as UTF8, UTF16BE or UTF16LE into
  * a predictable UTF8 string consistant with svg requirements.
  */
-std::string getString(const GooString *value)
+std::string getString(const std::string &value)
 {
+    char *str = nullptr;
+    int stringLength;
+
     if (_POPPLER_HAS_UNICODE_BOM(value)) {
-        return g_convert(value->getCString () + 2, get_goostring_length(*value) - 2,
-                         "UTF-8", "UTF-16BE", NULL, NULL, NULL);
+        str = g_convert(value.c_str() + 2, value.size() - 2,
+                        "UTF-8", "UTF-16BE", NULL, NULL, NULL);
     } else if (_POPPLER_HAS_UNICODE_BOMLE(value)) {
-        return g_convert(value->getCString () + 2, get_goostring_length(*value) - 2,
-                         "UTF-8", "UTF-16LE", NULL, NULL, NULL);
+        str = g_convert(value.c_str() + 2, value.size() - 2,
+                        "UTF-8", "UTF-16LE", NULL, NULL, NULL);
     }
-    return value->toStr();
+#if POPPLER_CHECK_VERSION(25,02,0)
+    else if (auto utf16 = pdfDocEncodingToUTF16(value); !utf16.empty())  {
+        str = g_convert(utf16.c_str(), utf16.length(), "UTF-8", "UTF-16", NULL, NULL, NULL);
+    }
+#else
+    else if (auto utf16 = pdfDocEncodingToUTF16(value, &stringLength))  {
+        str = g_convert(utf16, stringLength, "UTF-8", "UTF-16", NULL, NULL, NULL);
+        delete[] utf16;
+    }
+#endif
+    if (str) {
+        std::string copy = str;
+        g_free(str);
+        return copy;
+    }
+    g_warning("Couldn't parse text in PDF from UTF16.");
+    return "";
 }
 
 void pdf_debug_array(const Array *array, int depth, XRef *xref)
@@ -656,7 +697,11 @@ void pdf_debug_object(const Object *obj, int depth, XR
     } else if (obj->isArray()) {
         pdf_debug_array(obj->getArray(), depth, xref);
     } else if (obj->isString()) {
+#if POPPLER_CHECK_VERSION(26, 4, 0)
+        std::cout << " STR '" << obj->getString().c_str() << "'";
+#else
         std::cout << " STR '" << obj->getString()->getCString() << "'";
+#endif
     } else if (obj->isName()) {
         std::cout << " NAME '" << obj->getName() << "'";
     } else if (obj->isBool()) {
