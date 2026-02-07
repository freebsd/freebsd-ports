--- src/commandline.cpp.orig	2004-12-02 03:43:43 UTC
+++ src/commandline.cpp
@@ -221,7 +221,7 @@ int transcode_init(int argc, char **argv
 	return 1;
 }
 
-main(int argc, char **argv) {
+int main(int argc, char **argv) {
 	int processID = 0;
 	transcode_init(argc, argv);
 	return transcode_main();
