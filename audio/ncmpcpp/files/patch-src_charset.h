--- src/charset.h.orig
+++ src/charset.h
@@ -25,10 +25,10 @@
 #include <config.h>
 #endif
 
-#include <string>
-
 #if defined(SUPPORTED_LOCALES) && defined(HAVE_ICONV_H)
 
+#include <string>
+
 void init_current_locale();
 
 void utf_to_locale(std::string &);
@@ -42,16 +42,16 @@ void str_pool_locale_to_utf(char *&);
 
 #else
 
-void init_current_locale() { }
+#define init_current_locale();
 
-void utf_to_locale(std::string &) { }
-void locale_to_utf(std::string &) { }
+#define utf_to_locale(x);
+#define locale_to_utf(x);
 
-std::string &utf_to_locale_cpy(const std::string &s) { return s; }
-std::string &locale_to_utf_cpy(const std::string &s) { return s; }
+#define utf_to_locale_cpy(x) (x)
+#define locale_to_utf_cpy(x) (x)
 
-void str_pool_utf_to_locale(char *&) { }
-void str_pool_locale_to_utf(char *&) { }
+#define str_pool_utf_to_locale(x);
+#define str_pool_locale_to_utf(x);
 
 #endif // SUPPORTED_LOCALES && HAVE_ICONV_H
