--- main.cpp.orig	Tue Aug 23 22:26:20 2005
+++ main.cpp	Sat Feb 11 07:53:56 2006
@@ -19,6 +19,7 @@
 #include "file.h"
 #include "game.h"
 #include "systemstub.h"
+#include <sys/stat.h>
 
 static const char *USAGE = 
 	"REminiscence - Flashback Interpreter\n"
@@ -59,8 +60,15 @@
 
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
 	for (int i = 1; i < argc; ++i) {
 		bool opt = false;
 		if (strlen(argv[i]) >= 2) {
@@ -79,5 +87,6 @@
 	g->run();
 	delete g;
 	delete stub;
+	free(buf);
 	return 0;
 }
