--- src/mail.c.orig	2008-05-24 01:14:42.000000000 +0200
+++ src/mail.c	2013-09-13 17:37:30.649560538 +0200
@@ -1422,7 +1422,7 @@
     froms=strbuf(NULL);
 
     if((fp=fopen(mascot->mail.file,"r"))==NULL){
-	return;
+	return(NULL);
     }
     
     while(!feof(fp)){
@@ -1545,7 +1545,7 @@
     froms=strbuf(NULL);
 
     if ((dp=opendir(mascot->mail.file))==NULL){
-	return;
+	return(NULL);
     }	
     
 
