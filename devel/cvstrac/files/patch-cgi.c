--- ./cgi.c.orig	2006-12-13 19:45:51.000000000 -0500
+++ ./cgi.c	2009-11-09 17:15:57.000000000 -0500
@@ -57,13 +57,6 @@
 #endif /* INTERFACE */
 
 /*
-** Provide a reliable implementation of a caseless string comparison
-** function.
-*/
-#define stricmp sqlite3StrICmp
-extern int sqlite3StrICmp(const char*, const char*);
-
-/*
 ** The body of the HTTP reply text is stored here.
 */
 static int nAllocTxt = 0; /* Amount of space allocated for HTTP reply text */
@@ -669,17 +662,17 @@
       nArg = tokenize_line(zLine, sizeof(azArg)/sizeof(azArg[0]), azArg);
       for(i=0; i<nArg; i++){
         int c = tolower(azArg[i][0]);
-        if( c=='c' && stricmp(azArg[i],"content-disposition:")==0 ){
+        if( c=='c' && strcasecmp(azArg[i],"content-disposition:")==0 ){
           i++;
-        }else if( c=='n' && stricmp(azArg[i],"name=")==0 ){
+        }else if( c=='n' && strcasecmp(azArg[i],"name=")==0 ){
           zName = azArg[++i];
-        }else if( c=='f' && stricmp(azArg[i],"filename=")==0 ){
+        }else if( c=='f' && strcasecmp(azArg[i],"filename=")==0 ){
           char *z = azArg[++i];
           if( zName && z ){
             cgi_set_parameter_nocopy(mprintf("%s:filename",zName), z);
           }
           showBytes = 1;
-        }else if( c=='c' && stricmp(azArg[i],"content-type:")==0 ){
+        }else if( c=='c' && strcasecmp(azArg[i],"content-type:")==0 ){
           char *z = azArg[++i];
           if( zName && z ){
             cgi_set_parameter_nocopy(mprintf("%s:mimetype",zName), z);
