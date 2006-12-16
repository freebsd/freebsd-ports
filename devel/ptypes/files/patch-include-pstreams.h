--- include/pstreams.h.orig	Sat Dec 16 19:39:35 2006
+++ include/pstreams.h	Sat Dec 16 19:44:05 2006
@@ -266,6 +266,8 @@
 // internal class used in fdxstm
 //
 
+class fdxstm;
+
 class ptpublic fdxoutstm: public outstm
 {
     friend class fdxstm;
@@ -740,6 +742,8 @@
 #  pragma warning (disable: 4251)
 #endif
 
+
+class unit_thread;
 
 class ptpublic unit: public component
 {
