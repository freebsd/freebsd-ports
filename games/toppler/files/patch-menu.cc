--- menu.cc.orig	Sat Jan 19 11:08:41 2002
+++ menu.cc	Sat Jan 19 11:11:09 2002
@@ -10,6 +10,9 @@
 
 #include <stdlib.h>
 
+#define SCOREDIR	"%SCOREDIR%"
+#define SCOREFILE	"%SCOREFILE%"
+
 static unsigned short menupicture, titledata;
 static unsigned char currentmission = 0;
 
@@ -175,7 +178,7 @@
 static void getscores() {
   char n[300];
 
-  sprintf(n, "%s/nebulous.hsc", getenv("HOME"));
+  sprintf(n, "%s/%s", SCOREDIR, SCOREFILE);
   FILE *f = fopen(n, "rb");
 
   if (f) {
@@ -195,7 +198,7 @@
 static void savescores() {
   char n[300];
 
-  sprintf(n, "%s/nebulous.hsc", getenv("HOME"));
+  sprintf(n, "%s/%s", SCOREDIR, SCOREFILE);
 
   FILE *f = fopen(n, "r+b");
 
