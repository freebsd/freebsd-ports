--- src/cata_tiles.cpp.orig	2014-11-17 06:09:38.000000000 +0300
+++ src/cata_tiles.cpp	2014-11-30 11:56:51.119502150 +0300
@@ -164,9 +164,6 @@ void cata_tiles::get_tile_information(st
 int cata_tiles::load_tileset(std::string path, int R, int G, int B)
 {
     std::string img_path = path;
-#ifdef PREFIX   // use the PREFIX path over the current directory
-    img_path = (FILENAMES["datadir"] + "/" + img_path);
-#endif
     /** reinit tile_atlas */
     SDL_Surface *tile_atlas = IMG_Load(img_path.c_str());
 
