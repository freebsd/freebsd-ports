--- bindings/c++/gdaConnection.h.orig	Sat Jun 15 17:00:34 2002
+++ bindings/c++/gdaConnection.h	Sat Jun 15 17:00:54 2002
@@ -20,6 +20,8 @@
 #ifndef __gda_bindings_cpp_gdaConnectionH
 #define __gda_bindings_cpp_gdaConnectionH
 
+using namespace std;
+
 namespace gda {
 
 class Recordset;
