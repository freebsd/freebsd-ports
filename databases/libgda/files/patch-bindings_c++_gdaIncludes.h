--- bindings/c++/gdaIncludes.h.orig	Sat Jun 15 16:53:57 2002
+++ bindings/c++/gdaIncludes.h	Sat Jun 15 16:55:03 2002
@@ -51,4 +51,8 @@
 #include "gdaRecordset.h"
 #include "gdaValue.h"
 
+// Needed to get references to string working without having to pre-pend
+// std:: to each one.
+using namespace std;
+
 #endif // __gda_bindings_cpp_gdaIncludesH
