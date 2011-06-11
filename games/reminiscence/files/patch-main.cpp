--- main.cpp.orig	2011-03-10 23:37:01.000000000 +0300
+++ main.cpp	2011-05-05 11:40:07.000000000 +0400
@@ -19,6 +19,7 @@
 #include "fs.h"
 #include "game.h"
 #include "systemstub.h"
+#include <sys/stat.h>
 
 static const char *USAGE =
 	"REminiscence - Flashback Interpreter\n"
@@ -83,8 +84,15 @@
 
 #undef main
 int main(int argc, char *argv[]) {
+	char *homedir = getenv("HOME");
+	char *dotdir = "/.REminiscence";
+	char *buf = (char*)malloc(strlen(homedir) + strlen(dotdir) + 1);
+	strcpy(buf, homedir);
+	strcat(buf, dotdir);
+	mkdir(buf, 0755);
+
 	const char *dataPath = "DATA";
-	const char *savePath = ".";
+	const char *savePath = buf;
 	const char *levelNum = "0";
 	for (int i = 1; i < argc; ++i) {
 		bool opt = false;
@@ -111,5 +119,6 @@
 	g->run();
 	delete g;
 	delete stub;
+	free(buf);
 	return 0;
 }
