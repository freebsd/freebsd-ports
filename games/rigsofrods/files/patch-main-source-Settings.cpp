--- main/source/Settings.cpp.orig	2009-02-22 20:59:55.000000000 +0300
+++ main/source/Settings.cpp	2009-04-09 07:24:33.000000000 +0400
@@ -123,17 +123,10 @@
 	//true program path is impossible to get from POSIX functions
 	//lets hack!
 	pid_t pid = getpid();
-	char procpath[256];
-	sprintf(procpath, "/proc/%d/exe", pid);
-	int ch = readlink(procpath,program_path,240);
-	if (ch != -1)
-	{
-		program_path[ch] = 0;
-		path_descend(program_path);
-	} else return false;
+	strcpy(program_path, "%%DATADIR%%/");
 	//user path is easy
 	strncpy(user_path, getenv ("HOME"), 240);
-	sprintf(user_path, "%s/RigsOfRods/", user_path);
+	sprintf(user_path, "%s/.RigsOfRods/", user_path);
 #elif OGRE_PLATFORM == OGRE_PLATFORM_APPLE
 	//found this code, will look later
 	std::string path = "./";
