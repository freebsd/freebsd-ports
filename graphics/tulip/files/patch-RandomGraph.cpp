--- plugins/import/RandomGraph.cpp.orig	Fri Jan 10 12:57:54 2003
+++ plugins/import/RandomGraph.cpp	Fri Jan 10 12:58:04 2003
@@ -1,3 +1,4 @@
+#include <sys/types.h>
 #include <sys/timeb.h>
 #include<qinputdialog.h>
 #include <tulip/TulipPlugin.h>
@@ -9,7 +10,7 @@
 };
 
 namespace std {
-  struct less<edgeS>
+  template <> struct less<edgeS>
   {
     bool operator()(const edgeS &c,const edgeS &d) const
     {
