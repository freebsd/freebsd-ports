--- plugins/import/CirculantGraph.cpp.orig	Thu Apr  3 04:49:37 2003
+++ plugins/import/CirculantGraph.cpp	Mon May 26 08:01:03 2003
@@ -1,5 +1,6 @@
+#include <sys/types.h>
 #include <sys/timeb.h>
-#include<qinputdialog.h>
+#include <qinputdialog.h>
 #include <tulip/TulipPlugin.h>
 
 using namespace std;
@@ -9,7 +10,7 @@
 };
 
 namespace std {
-  struct less<edgeS>
+  template <> struct less<edgeS>
   {
     bool operator()(const edgeS &c,const edgeS &d) const
     {
