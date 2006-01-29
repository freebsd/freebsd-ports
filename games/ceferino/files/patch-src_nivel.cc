--- src/nivel.cc	Sat Jan 28 19:31:44 2006
+++ src/nivel.cc	Sat Jan 28 19:32:49 2006
@@ -166,7 +166,7 @@
 	char tmp[1024];
 
 #ifdef WIN32
-	strcpy(tmp, SRC_DIR "/niveles/base.map");
+	strcpy(tmp, SRC_DIR "/levels/base.map");
 #else
 	strcpy(tmp, getenv("HOME"));
 	strcat(tmp, "/");
@@ -175,12 +175,12 @@
 	arch = fopen(tmp, "rb");
 
 	if (!arch)
-		arch = fopen (DATADIR "/niveles/base.map", "rb");
+		arch = fopen (DATADIR "/levels/base.map", "rb");
 
 	if (!arch)
 	{
 		printf(_("Can't open the file '%s'"), DATADIR\
-				"/niveles/base.map'\n");
+				"/levels/base.map'\n");
 		exit(-1);
 	}
 
