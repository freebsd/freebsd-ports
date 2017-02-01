--- src/GBA.cpp.orig	2004-05-13 14:37:59 UTC
+++ src/GBA.cpp
@@ -1130,7 +1130,7 @@ bool CPUWriteBMPFile(const char *fileNam
 bool CPUIsZipFile(const char * file)
 {
   if(strlen(file) > 4) {
-    char * p = strrchr(file,'.');
+    const char * p = strrchr(file,'.');
 
     if(p != NULL) {
       if(_stricmp(p, ".zip") == 0)
@@ -1145,7 +1145,7 @@ bool CPUIsGBAImage(const char * file)
 {
   cpuIsMultiBoot = false;
   if(strlen(file) > 4) {
-    char * p = strrchr(file,'.');
+    const char * p = strrchr(file,'.');
 
     if(p != NULL) {
       if(_stricmp(p, ".gba") == 0)
@@ -1169,7 +1169,7 @@ bool CPUIsGBAImage(const char * file)
 bool CPUIsGBABios(const char * file)
 {
   if(strlen(file) > 4) {
-    char * p = strrchr(file,'.');
+    const char * p = strrchr(file,'.');
 
     if(p != NULL) {
       if(_stricmp(p, ".gba") == 0)
@@ -1189,7 +1189,7 @@ bool CPUIsGBABios(const char * file)
 bool CPUIsELF(const char *file)
 {
   if(strlen(file) > 4) {
-    char * p = strrchr(file,'.');
+    const char * p = strrchr(file,'.');
     
     if(p != NULL) {
       if(_stricmp(p, ".elf") == 0)
