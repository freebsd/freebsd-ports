--- bindings/c++/gdaHelpers.h.orig	Sat Jun 15 17:04:17 2002
+++ bindings/c++/gdaHelpers.h	Sat Jun 15 17:04:31 2002
@@ -19,6 +19,8 @@
 //#ifndef __gda_helpers_cpp_gdaHelpersH
 //#define __gda_helpers_cpp_gdaHelpersH
 
+using namespace std;
+
 namespace gda {
 string gda_return_string (gchar* pszString);
 };
