--- src/language.hpp.orig	Mon May  3 18:35:49 2004
+++ src/language.hpp	Wed May 12 00:50:43 2004
@@ -19,6 +19,14 @@
 #include <string>
 #include <vector>
 
+#if (__FreeBSD_version < 500029)
+#include <cwchar>
+namespace std
+{
+	typedef basic_string <wchar_t> wstring;
+}
+#endif
+
 //this module controls internationalization.
 
 struct symbol_table
