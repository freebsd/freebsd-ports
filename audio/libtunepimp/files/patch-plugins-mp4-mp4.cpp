--- plugins/mp4/mp4.cpp.orig	2006-11-18 12:51:08.000000000 +0200
+++ plugins/mp4/mp4.cpp	2010-06-07 10:36:19.151889361 +0300
@@ -231,9 +231,7 @@ mp4ReadMetadata(metadata_t *mdata, const
   
   strcpy(mdata->fileFormat, fileName + strlen(fileName) - 3); 
   
-  if (!MP4Close(mp4file))
-    return 0;
-  
+  MP4Close(mp4file);
   return 1;
 }
 
@@ -315,8 +313,7 @@ mp4WriteMetadata(const metadata_t *mdata
   sprintf(temp, "%d", mdata->nonAlbum);  
   MP4SetMetadataFreeForm(mp4file, "MusicBrainz Non-Album", (u_int8_t *)temp, strlen(temp) + 1);
   
-  if (!MP4Close(mp4file))
-    return 0;
+  MP4Close(mp4file);
 
 #ifndef WIN32
   if (!MP4Optimize(utf8ToEncoding(fileName, encoding).c_str()))
