--- src/ConfigReader.cpp.orig	Sat Feb  8 20:50:08 2003
+++ src/ConfigReader.cpp	Sat Feb  8 20:50:32 2003
@@ -151,7 +151,7 @@
 
    for(i=0;i<count;i++) {
       if (Match(i,name)) {
-      co=strdupa(data[i].string);
+      co=strdup(data[i].string);
       if (co) {
       tok=strtok(co,se); r=atoi(tok);
       tok=strtok(NULL,se); g=atoi(tok);
