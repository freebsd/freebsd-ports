--- src/anchors.c.orig	2016-05-11 21:46:55 UTC
+++ src/anchors.c
@@ -225,7 +225,7 @@ char* rolltonum(char* str) {
   return &str[i];
 }
 
-int getline(FILE* infile, hll* tt) {
+int get_line(FILE* infile, hll* tt) {
   char temp[1024];
   char* help;
   int z, h;
@@ -248,7 +248,7 @@ hll* parseCHAOS(FILE* infile, int* totnu
   *totnum = 0;
   while(!feof(infile)) {
     tt = (hll*) malloc(sizeof(hll));
-    while (!feof(infile) && !getline(infile, tt))
+    while (!feof(infile) && !get_line(infile, tt))
       ;
     if (feof(infile)) break;
     if (gapfreechunks) {
