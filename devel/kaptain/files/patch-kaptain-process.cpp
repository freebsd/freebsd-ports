--- kaptain/process.cpp.orig	Wed Aug 14 12:17:25 2002
+++ kaptain/process.cpp	Fri Dec 20 16:14:31 2002
@@ -8,6 +8,7 @@
 
 /* ---------------------------------------------------------------------- */
 
+using namespace std;
 
 void clean_up_child_process(int s)
 {
