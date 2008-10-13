--- src/main.cpp.orig	2008-10-10 01:21:19.000000000 +0400
+++ src/main.cpp	2008-10-13 04:20:11.000000000 +0400
@@ -134,6 +134,8 @@
 // Main entry point
 int main(int argc, char *argv[])
 {
+	chdir(DATADIR);
+
 	printf(GAMENAME " " LX_VERSION " is starting ...\n");
 #ifdef DEBUG
 	printf("HINT: This is a DEBUG build.\n");
