--- ./ym2wav.cpp.orig	2010-04-23 13:49:47.000000000 +0200
+++ ./ym2wav.cpp	2010-04-23 13:49:47.000000000 +0200
@@ -71,7 +71,7 @@
 
 int main(int argc, char* argv[])
 {
-	char *platform;
+	const char *platform;
 
 	if (PLATFORM)
 		platform = "64bit";
