--- main.cpp.orig	2016-03-02 09:36:17 UTC
+++ main.cpp
@@ -125,8 +125,15 @@ static const int DEFAULT_SCALER = SCALER
 
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
 	int levelNum = 0;
 	int scaler = DEFAULT_SCALER;
 	bool fullscreen = false;
@@ -191,5 +198,6 @@ int main(int argc, char *argv[]) {
 	delete g;
 	stub->destroy();
 	delete stub;
+	free(buf);
 	return 0;
 }
