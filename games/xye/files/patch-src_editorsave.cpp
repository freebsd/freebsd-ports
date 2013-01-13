--- src/editorsave.cpp.orig	2013-01-13 21:51:34.000000000 +0100
+++ src/editorsave.cpp	2013-01-13 21:50:22.000000000 +0100
@@ -636,16 +636,16 @@
         }
         saveColorStuff(file, board);
     
-        int i,j;
+        int k,j;
         file << "\t<ground>\n";
         resetSavedPosition();
-        for (i=0;i<XYE_HORZ;i++) for (j=0;j<XYE_VERT;j++) saveGroundObject(file,editor::board->objects[i][j],i,XYE_VERT-j-1);
+        for (k=0;k<XYE_HORZ;k++) for (j=0;j<XYE_VERT;j++) saveGroundObject(file,editor::board->objects[k][j],k,XYE_VERT-j-1);
         file << "\t</ground>\n";
         file << "\t<objects>\n";
         resetSavedPosition();
-        for (i=0;i<XYE_HORZ;i++) for (j=0;j<XYE_VERT;j++)
+        for (k=0;i<XYE_HORZ;k++) for (j=0;j<XYE_VERT;j++)
         {
-            saveNormalObject(file,editor::board->objects[i][j],i,XYE_VERT-j-1);
+            saveNormalObject(file,editor::board->objects[k][j],k,XYE_VERT-j-1);
         }
         savePortals( file, editor::board);
         
