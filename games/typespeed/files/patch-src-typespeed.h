--- src/typespeed.h.orig	2008-08-13 14:36:51 UTC
+++ src/typespeed.h
@@ -44,6 +44,7 @@ struct finfo {
 	char descr[61];
 	char name[MAXPATHLEN];
 };
+extern struct finfo finfo;
 
 struct stats {
 	uint8_t level;
@@ -56,7 +57,8 @@ struct stats {
 	clock_t duration;
 	unsigned int sinit;
 	char name[21];
-} now;
+};
+extern struct stats now;
 
 struct opt {
 	int cheat;
@@ -66,7 +68,8 @@ struct opt {
 	int usecolors;
 	char name[21];
 	char order[3];
-} opt;
+};
+extern struct opt opt;
 
 struct rules {
 	int misses;
@@ -85,12 +88,13 @@ struct rules {
 	int maxtime;
 	char name[31];
 	char fname[FILENAME_MAX + 1];
-} rules;
+};
+extern struct rules rules;
 
 struct rawdata {
 	char *bulk;
 	char **word;
 	size_t n;
 	size_t max;
-} words;
-
+};
+extern struct rawdata words;
