--- trackercore/loader_s3m.cpp.orig	Thu Sep  6 14:37:45 2001
+++ trackercore/loader_s3m.cpp	Fri Dec 27 21:54:34 2002
@@ -346,7 +346,7 @@
 
 }
 
-void Loader_S3M::free_info(bool free_sampledata=false) {
+void Loader_S3M::free_info(bool free_sampledata) {
 
 	int i;
 
