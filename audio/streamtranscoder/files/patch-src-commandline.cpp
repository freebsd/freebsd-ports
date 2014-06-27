--- src/commandline.cpp.orig	2014-06-08 18:46:55.585823061 +0100
+++ src/commandline.cpp	2014-06-08 18:47:13.735820885 +0100
@@ -221,7 +221,7 @@
 	return 1;
 }
 
-main(int argc, char **argv) {
+int main(int argc, char **argv) {
 	int processID = 0;
 	transcode_init(argc, argv);
 	return transcode_main();
