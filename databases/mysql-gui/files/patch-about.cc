--- about.cc.orig	Wed Sep  3 19:04:33 2003
+++ about.cc	Wed Sep  3 19:04:46 2003
@@ -11,6 +11,7 @@
 #include <stdio.h>
 #endif
 #include <string>
+using namespace std;
 extern string c_info,s_info;
 static Fl_Double_Window *xxx=(Fl_Double_Window *)0;
 Fl_Window *splash=(Fl_Window *)0;
