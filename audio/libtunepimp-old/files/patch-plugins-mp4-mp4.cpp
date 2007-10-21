--- plugins/mp4/mp4.cpp.orig	Sun Jan 22 13:13:15 2006
+++ plugins/mp4/mp4.cpp	Sun Oct 21 07:45:19 2007
@@ -224,9 +224,7 @@
   
   strcpy(mdata->fileFormat, fileName + strlen(fileName) - 3); 
   
-  if (!MP4Close(mp4file))
-    return 0;
-  
+  MP4Close(mp4file);
   return 1;
 }
 
@@ -306,8 +304,7 @@
   sprintf(temp, "%d", mdata->nonAlbum);  
   MP4SetMetadataFreeForm(mp4file, "MusicBrainz Non-Album", (u_int8_t *)temp, strlen(temp) + 1);
   
-  if (!MP4Close(mp4file))
-    return 0;
+  MP4Close(mp4file);
   
   return 1;
 }
