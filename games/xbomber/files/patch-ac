--- xbomber.c.orig	Sat Jun 20 11:09:35 1998
+++ xbomber.c	Sat Aug 12 03:09:36 2000
@@ -1599,7 +1599,7 @@
   /* Get -color switch: */
 
   use_color = 0;
-  strcpy(graphicsset, "./pixmaps");
+  strcpy(graphicsset, DATADIR "/pixmaps");
   
   if (argc >= 2)
     {
@@ -1683,7 +1683,7 @@
 	      
 	      for (i = 0; i < NUM_SOUNDS; i++)
 		{
-		  sprintf(file, "sounds/%s.au", sound_names[i]);
+		  sprintf(file, DATADIR "/sounds/%s.au", sound_names[i]);
 		  
 		  fi = fopen(file, "r");
 		  if (fi != NULL)
@@ -1720,7 +1720,7 @@
 	      
 	      for (i = 0; i < NUM_NSOUNDS; i++)
 		{
-		  sprintf(file, "sounds/numbers/%s.au", nsound_names[i]);
+		  sprintf(file, DATADIR "/sounds/numbers/%s.au", nsound_names[i]);
 		  
 		  fi = fopen(file, "r");
 		  if (fi != NULL)
@@ -2096,23 +2096,23 @@
   
   /* Make cursor: */
   
-  ret = XReadBitmapFile(display[pln], window[pln], "bitmaps/cursor.xbm",
+  ret = XReadBitmapFile(display[pln], window[pln], DATADIR "/bitmaps/cursor.xbm",
 			&tempint1, &tempint2, &cursor_pixmap[pln],
 			&tempint3, &tempint4);
   
   if (ret != BitmapSuccess)
     {
-      perror("bitmaps/cursor.xbm");
+      perror(DATADIR "/bitmaps/cursor.xbm");
       exit(1);
     }
   
-  ret = XReadBitmapFile(display[pln], window[pln], "bitmaps/cursor-mask.xbm",
+  ret = XReadBitmapFile(display[pln], window[pln], DATADIR "/bitmaps/cursor-mask.xbm",
 			&tempint1, &tempint2, &cursor_mask[pln],
 			&tempint3, &tempint4);
   
   if (ret != BitmapSuccess)
     {
-      perror("bitmaps/cursor-mask.xbm");
+      perror(DATADIR "/bitmaps/cursor-mask.xbm");
       exit(1);
     }
   
@@ -2149,7 +2149,7 @@
 							    black[pln],
 							    has_color[pln]));
 	      
-	      sprintf(file, "bitmaps/%s.xbm", object_names[i]);
+	      sprintf(file, DATADIR "/bitmaps/%s.xbm", object_names[i]);
 	      
 	      ret = XReadBitmapFile(display[pln], window[pln], file, 
 				    &tempint1, &tempint2,
@@ -2863,7 +2863,7 @@
   
   /* Load level layout on top of this: */
   
-  sprintf(filename, "levels/level%.2d.dat", level);
+  sprintf(filename, DATADIR "/levels/level%.2d.dat", level);
   
   fi = fopen(filename, "r");
   if (fi == NULL)
@@ -3303,7 +3303,7 @@
     {
       c = '.';
       
-      sprintf(file, "pixmaps/%s.ppm", object_names[i]);
+      sprintf(file, DATADIR "/pixmaps/%s.ppm", object_names[i]);
       
       fi = fopen(file, "r");
       if (fi == NULL)
