--- ./load.cpp.orig	2000-02-15 03:47:39.000000000 +0100
+++ ./load.cpp	2013-12-28 11:39:16.000000000 +0100
@@ -81,7 +81,7 @@
 	SDL_Surface *bmp, *title;
 	
 	/* Open the title file -- we know its colormap is our global one */
-	sprintf(file, "Images"DIR_SEP"Maelstrom_Titles#%d.bmp", title_id);
+	snprintf(file, sizeof(file), "Images"DIR_SEP"Maelstrom_Titles#%d.bmp", title_id);
 	bmp = SDL_LoadBMP(path.Path(file));
 	if ( bmp == NULL ) {
 		return(NULL);
@@ -103,7 +103,7 @@
 	Uint16 w, h;
 	
 	/* Open the cicn sprite file.. */
-	sprintf(file, "Images"DIR_SEP"Maelstrom_Icon#%hd.cicn", cicn_id);
+	snprintf(file, sizeof(file), "Images"DIR_SEP"Maelstrom_Icon#%hd.cicn", cicn_id);
 	if ( (cicn_src=SDL_RWFromFile(path.Path(file), "r")) == NULL ) {
 		error("GetCIcon(%hd): Can't open CICN %s: ",
 					cicn_id, path.Path(file));
