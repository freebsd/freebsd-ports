--- base/main.cpp.orig	Tue Aug  3 15:56:29 2004
+++ base/main.cpp	Tue Aug  3 15:56:41 2004
@@ -262,7 +262,7 @@
 
 	// Free up memory
 	delete engine;
-};
+}
 
 #ifndef _WIN32_WCE
 int main(int argc, char *argv[]) {
