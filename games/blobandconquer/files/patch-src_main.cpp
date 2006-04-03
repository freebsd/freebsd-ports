--- src/main.cpp.orig	Mon Apr  3 06:07:33 2006
+++ src/main.cpp	Mon Apr  3 06:08:15 2006
@@ -88,6 +88,7 @@
 
 int main(int argc, char *argv[])
 {
+	chdir(PAKLOCATION);
 	atexit(cleanup);
 	
 	loadLocaleIndex();
