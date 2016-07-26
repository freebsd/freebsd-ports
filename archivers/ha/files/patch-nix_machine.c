--- nix/machine.c.orig	1995-01-12 06:53:00 UTC
+++ nix/machine.c
@@ -417,7 +417,7 @@ char *md_stripname(char *mdfullpath) {
     if (plainname!=NULL) free(plainname),plainname=NULL;
     if ((plainname=malloc(strlen(mdfullpath)+1))==NULL) 
       error(1,ERR_MEM,"md_stripname()");
-    for (i=strlen(mdfullpath)-1;i>0;i--) {
+    for (i=strlen(mdfullpath)-1;i>=0;i--) {
 	if (mdfullpath[i]=='/') {
 	    i++;
 	    break;
