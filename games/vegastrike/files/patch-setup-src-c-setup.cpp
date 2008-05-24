--- setup/src/c/setup.cpp.orig	2008-04-24 16:16:49.000000000 +0400
+++ setup/src/c/setup.cpp	2008-05-08 16:55:40.000000000 +0400
@@ -25,6 +25,7 @@
 #include <stdio.h>
 #include <unistd.h>
 #include <pwd.h>
+#include <sys/stat.h>
 #include <sys/types.h>
 
 #endif
@@ -33,6 +34,57 @@
 using std::string;
 using std::vector;
 char origpath[65536];
+
+static void changeToProgramDirectory(char *argv0) {
+    int ret = -1; /* Should it use argv[0] directly? */
+    char *program = argv0;
+#ifndef _WIN32
+    char buf[65536];
+    {
+	char linkname[128]; /* /proc/<pid>/exe */
+	linkname[0]='\0';
+	pid_t pid;
+	
+	/* Get our PID and build the name of the link in /proc */
+	pid = getpid();
+	
+	sprintf(linkname, "/proc/%d/exe", pid);
+	ret = readlink(linkname, buf, 65535);
+	if (ret <= 0) {
+		sprintf(linkname, "/proc/%d/file", pid);
+		ret = readlink(linkname, buf, 65535);
+	}
+	if (ret <= 0) {
+		ret = readlink(program, buf, 65535);
+	}
+	if (ret > 0) {
+		buf[ret]='\0';
+		/* Ensure proper NUL termination */
+		program = buf;
+	}
+    }
+#endif
+
+    char *parentdir;
+    int pathlen=strlen(program);
+    parentdir=new char[pathlen+1];
+    char *c;
+    strncpy ( parentdir, program, pathlen+1 );
+    c = (char*) parentdir;
+    while (*c != '\0')     /* go to end */
+      c++;
+    
+    while ((*c != '/')&&(*c != '\\')&&c>parentdir)      /* back up to parent */
+      c--;
+    
+    *c = '\0';             /* cut off last part (binary name) */
+    if (strlen (parentdir)>0) {
+      chdir (parentdir);/* chdir to the binary app's parent */
+    }
+    delete []parentdir;
+}
+
+
 #if defined(_WINDOWS)&&defined(_WIN32)
 typedef char FileNameCharType [65536];
 int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nShowCmd) {
@@ -44,20 +96,21 @@
 #else
 int main(int argc, char *argv[]) {
 #endif
-#if 1
-//def _WIN32
+
+	if (argc>1) {
+		if (strcmp(argv[1], "--target")==0 && argc>2) {
+			chdir(argv[2]);
+		} else {
+			fprintf(stderr,"Usage: vssetup [--target DATADIR]\n");
+			return 1;
+		}
+	}
 	getcwd (origpath,65535);
 	origpath[65535]=0;
-        int i;
-	for (i=strlen(argv[0]);argv[0][i]!='\\'&&argv[0][i]!='/'&&i>=0;i--) {
-	}
-	argv[0][i+1]='\0';
-	if (i>=0) {
-		chdir(argv[0]);
-	}
-#endif
 	
-	{	
+	changeToProgramDirectory(argv[0]);
+	
+	{
 		vector<string>	data_paths;
 #ifdef DATA_DIR
 		data_paths.push_back( DATA_DIR);
@@ -69,6 +122,7 @@
 		data_paths.push_back( string(origpath)+"/data4.x");
 		data_paths.push_back( string(origpath)+"/data");
 		data_paths.push_back( string(origpath)+"/../data");
+		data_paths.push_back( string(origpath)+"/../Resources");
 		getcwd (origpath,65535);
 		origpath[65535]=0;
 		data_paths.push_back( ".");
@@ -79,6 +133,8 @@
 		data_paths.push_back( "../../data");
 		data_paths.push_back( "../Resources");
 		data_paths.push_back( "../Resources/data");
+		data_paths.push_back( "../Resources/data4.x");
+/*
 		data_paths.push_back( "/usr/share/local/vegastrike/data");
 		data_paths.push_back( "/usr/local/share/vegastrike/data");
 		data_paths.push_back( "/usr/local/vegastrike/data");
@@ -86,7 +142,6 @@
 		data_paths.push_back( "/usr/local/games/vegastrike/data");
 		data_paths.push_back( "/usr/games/vegastrike/data");
 		data_paths.push_back( "/opt/share/vegastrike/data");
-		data_paths.push_back( "../Resources/data4.x");
 		data_paths.push_back( "/usr/share/local/vegastrike/data4.x");
 		data_paths.push_back( "/usr/local/share/vegastrike/data4.x");
 		data_paths.push_back( "/usr/local/vegastrike/data4.x");
@@ -94,7 +149,7 @@
 		data_paths.push_back( "/usr/local/games/vegastrike/data4.x");
 		data_paths.push_back( "/usr/games/vegastrike/data4.x");
 		data_paths.push_back( "/opt/share/vegastrike/data4.x");
-		
+*/		
 		// Win32 data should be "."
 		char tmppath[16384];
 		for( vector<string>::iterator vsit=data_paths.begin(); vsit!=data_paths.end(); vsit++)
@@ -118,8 +173,8 @@
 #ifndef _WIN32
 	struct passwd *pwent;
 	pwent = getpwuid (getuid());
-        string HOMESUBDIR=".vegastrike";
 	
+	string HOMESUBDIR;
 	FILE *version=fopen("Version.txt","r");
 	if (!version)
 		version=fopen("../Version.txt","r");
@@ -135,13 +190,23 @@
 		if (hsd.length()) {
 			HOMESUBDIR=hsd;
 			//fprintf (STD_OUT,"Using %s as the home directory\n",hsd.c_str());
-		}			
+		}
+	}
+	if (HOMESUBDIR.empty()) {
+		fprintf(stderr,"Error: Failed to find Version.txt anywhere.\n");
+		return 1;
 	}
 	chdir (pwent->pw_dir);
-	chdir (HOMESUBDIR.c_str());
+
+	mkdir(HOMESUBDIR.c_str()
+#ifndef _WIN32
+		, 0755
 #endif
-#ifdef GTK
-#endif    //GTK
+		);
+
+#endif
+	chdir (HOMESUBDIR.c_str());
+	
 	Start(&argc,&argv);
 #if defined(_WINDOWS)&&defined(_WIN32)
 	delete []argv0;
