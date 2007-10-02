--- plugins/mp4/mp4.cpp.orig	2006-11-18 02:51:08.000000000 -0800
+++ plugins/mp4/mp4.cpp	2007-10-02 16:24:06.000000000 -0700
@@ -231,9 +231,7 @@
   
   strcpy(mdata->fileFormat, fileName + strlen(fileName) - 3); 
   
-  if (!MP4Close(mp4file))
-    return 0;
-  
+  MP4Close(mp4file);
   return 1;
 }
 
@@ -315,8 +313,7 @@
   sprintf(temp, "%d", mdata->nonAlbum);  
   MP4SetMetadataFreeForm(mp4file, "MusicBrainz Non-Album", (u_int8_t *)temp, strlen(temp) + 1);
   
-  if (!MP4Close(mp4file))
-    return 0;
+  MP4Close(mp4file);
 
 #ifndef WIN32
   if (!MP4Optimize(utf8ToEncoding(fileName, encoding).c_str()))
