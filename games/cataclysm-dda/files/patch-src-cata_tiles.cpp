--- src/cata_tiles.cpp.orig	2015-03-09 05:25:34 UTC
+++ src/cata_tiles.cpp
@@ -167,9 +167,6 @@ void cata_tiles::get_tile_information(st
 int cata_tiles::load_tileset(std::string path, int R, int G, int B)
 {
     std::string img_path = path;
-#ifdef PREFIX   // use the PREFIX path over the current directory
-    img_path = (FILENAMES["datadir"] + "/" + img_path);
-#endif
     /** reinit tile_atlas */
     SDL_Surface *tile_atlas = IMG_Load(img_path.c_str());
 
@@ -285,7 +282,7 @@ void cata_tiles::load_tilejson_from_file
         JsonArray tiles_new = config.get_array("tiles-new");
         while (tiles_new.has_more()) {
             JsonObject tile_part_def = tiles_new.next_object();
-            const std::string tileset_image_path = tile_part_def.get_string("file");
+            const std::string tileset_image_path = FILENAMES["datadir"] + "/" + tile_part_def.get_string("file");
             int R = -1;
             int G = -1;
             int B = -1;
