--- trackercore/sample.cpp.orig	Wed May  9 22:43:01 2001
+++ trackercore/sample.cpp	Fri Dec 27 21:53:58 2002
@@ -24,7 +24,7 @@
 Sample::~Sample(){
 }
 
-void Sample::reset(bool try_to_free_data=true) {
+void Sample::reset(bool try_to_free_data) {
 
 	name="";
 	filename="";
