--- src/widgets/textbox.hpp.orig	Mon May  3 18:35:49 2004
+++ src/widgets/textbox.hpp	Wed May 12 00:51:03 2004
@@ -22,6 +22,14 @@
 
 #include "SDL.h"
 
+#if (__FreeBSD_version < 500029)
+#include <cwchar>
+namespace std
+{
+	typedef basic_string <wchar_t> wstring;
+}
+#endif
+
 namespace gui {
 
 class textbox : public widget
