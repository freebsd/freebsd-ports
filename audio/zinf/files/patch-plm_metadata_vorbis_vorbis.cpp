--- plm/metadata/vorbis/vorbis.cpp.orig	2004-02-10 18:21:14 UTC
+++ plm/metadata/vorbis/vorbis.cpp
@@ -23,6 +23,7 @@ ________________________________________
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <unistd.h>
 #include <math.h>
 #include <assert.h>
 #include <string>
@@ -143,17 +143,18 @@ Vorbis::~Vorbis()
 bool Vorbis::WriteMetaData(const char *url, const MetaData & metadata)
 {
     char      dummy[20];
-    char     *ptr;
     bool     writetags;
     // We will support only id3-like tags.  For a more complete list see 
     //  http://reactor-core.org/ogg-tag-standard.html
 
-    ptr = strrchr(url, '.');
+    {
+    const char *ptr = strrchr(url, '.');
     if (ptr == NULL)
         return false;
 
     if (strcasecmp(ptr, ".ogg"))
         return false;  
+    }
 
     m_context->prefs->GetPrefBoolean(kWriteVorbisTagsPref, &writetags);
 
@@ -216,7 +217,7 @@ bool Vorbis::WriteMetaData(const char *u
     strncpy(newpath,path.c_str(),path.length());
     FILE *out = NULL;
 
-    ptr = strrchr(newpath, '.');
+    char *ptr = strrchr(newpath, '.');
     if (ptr) 
     {
         strcpy(ptr, "XXXXXX");
