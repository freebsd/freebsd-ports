--- trackercore/loader_it.cpp.orig	Wed May  1 09:11:51 2002
+++ trackercore/loader_it.cpp	Fri Dec 27 21:53:21 2002
@@ -192,7 +192,7 @@
 
 }
 
-void Loader_IT::free_info(bool free_sampledata=false) {
+void Loader_IT::free_info(bool free_sampledata) {
 
 	clear_structs(free_sampledata);
 }
