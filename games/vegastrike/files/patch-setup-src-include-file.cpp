--- setup/src/include/file.cpp.orig	2008-04-24 16:16:50.000000000 +0400
+++ setup/src/include/file.cpp	2008-05-09 04:41:07.000000000 +0400
@@ -15,6 +15,8 @@
  *                                                                         *
  **************************************************************************/
 #include <string>
+#include <sys/stat.h>
+
 using std::string;
 #include "file.h"
 extern char origpath[65536];
@@ -98,6 +100,17 @@
 string mangle_config (string config) {
 	return string(origpath)+string("/")+config;
 }
+
+bool useGameConfig(void) {
+	struct stat st1,st2;
+	if (stat(CONFIG.config_file, &st1)==0 && stat(mangle_config(CONFIG.config_file).c_str(), &st2)==0) {
+		if (st2.st_mtime > st1.st_mtime) {
+			return true;
+		}
+	}
+	return false;
+}
+
 void LoadConfig(void) {
 	FILE *fp;
 	char line[MAX_READ+1];
@@ -108,8 +121,7 @@
 	G_CURRENT = &GROUPS;
 	C_CURRENT = &CATS;
 
-
-	if ((fp = fopen(CONFIG.config_file, "r")) == NULL) {
+	if (useGameConfig() || (fp = fopen(CONFIG.config_file, "r")) == NULL) {
 		origconfig=true;
 		if ((fp = fopen(mangle_config(CONFIG.config_file).c_str(), "r")) == NULL) {
 			fprintf (stderr, "Unable to read from %s\n", CONFIG_FILE );
@@ -185,7 +197,8 @@
 	char *p, *parm, *n_parm, *start_write, *end_write;
 	int commenting = 0;		// 0 if scanning, 1 if adding comments, 2 if removing comments
 	int skip;
-	if ((rp = fopen(CONFIG.config_file, "r")) == NULL) {
+	
+	if (useGameConfig() || (rp = fopen(CONFIG.config_file, "r")) == NULL) {
 		if ((rp = fopen(mangle_config(CONFIG.config_file).c_str(), "r")) == NULL) {
 			fprintf (stderr, "Unable to read from %s\n", CONFIG_FILE );
 			exit(-1);
@@ -288,11 +301,20 @@
 		}
 	}
 	string tmp1 = CONFIG.config_file;
+/*
 	if(origconfig) {
 		tmp1 = mangle_config (CONFIG.config_file);
 	}
+*/
 	if ((wp = fopen(tmp1.c_str(), "w")) == NULL) {
-		fprintf (stderr, "Unable to write  to %s\n", CONFIG.config_file );
+		tmp1 = mangle_config (CONFIG.config_file);
+		if ((wp = fopen(tmp1.c_str(), "w")) == NULL) {
+			tmp1 = CONFIG.config_file;
+			if ((wp = fopen(tmp1.c_str(), "w")) == NULL) {
+				fprintf (stderr, "Unable to write  to %s\n", CONFIG.config_file );
+				exit(1);
+			}
+		}
 	}
 	while ((p = fgets(line, MAX_READ, rp)) != NULL) {
 		fprintf(wp, line);
