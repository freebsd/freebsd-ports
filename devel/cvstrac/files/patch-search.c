--- ./search.c.orig	2006-12-13 19:27:25.000000000 -0500
+++ ./search.c	2009-11-09 17:15:57.000000000 -0500
@@ -29,11 +29,6 @@
 
 
 /*
-** We'll use this routine in several places.
-*/
-extern int sqlite3StrNICmp(const char*,const char*,int);
-
-/*
 ** Search for a keyword in text.  Return a matching score:
 **
 **     0     No sign of the word was found in the text
@@ -54,7 +49,7 @@
   }
   if( n<=0 ) n = strlen(zWord);
   for(i=0; zText[i]; i++){
-    if( (zText[i]==c1 || zText[i]==c2) && sqlite3StrNICmp(zWord,&zText[i],n)==0){
+    if( (zText[i]==c1 || zText[i]==c2) && sqlite3_strnicmp(zWord,&zText[i],n)==0){
       int score = 6;
       if( (i==0 || !isalnum(zText[i-1]))
            && (zText[i+n]==0 || !isalnum(zText[i+n])) ){
@@ -282,7 +277,7 @@
           int n;
           if( tolower(c)!=tolower(azKey[k][0]) ) continue;
           n = keySize[k];
-          if( sqlite3StrNICmp(&zAll[j],azKey[k],n)==0 ){
+          if( sqlite3_strnicmp(&zAll[j],azKey[k],n)==0 ){
             strcpy(z,"<b>");
             z += 3;
             while( n ){
