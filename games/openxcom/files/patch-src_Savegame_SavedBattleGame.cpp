Corresponds to upstream commits 09f8473 and 7fe2dd9

--- src/Savegame/SavedBattleGame.cpp.orig	2014-06-13 21:14:43 UTC
+++ src/Savegame/SavedBattleGame.cpp
@@ -148,14 +148,14 @@
 		Tile::SerializationKey serKey;
 		size_t totalTiles = node["totalTiles"].as<size_t>();
 
-        memset(&serKey, 0, sizeof(Tile::SerializationKey));
-		serKey.index = node["tileIndexSize"].as<Uint8>(serKey.index);
+		memset(&serKey, 0, sizeof(Tile::SerializationKey));
+		serKey.index = node["tileIndexSize"].as<char>(serKey.index);
 		serKey.totalBytes = node["tileTotalBytesPer"].as<Uint32>(serKey.totalBytes);
-		serKey._fire = node["tileFireSize"].as<Uint8>(serKey._fire);
-		serKey._smoke = node["tileSmokeSize"].as<Uint8>(serKey._smoke);
-		serKey._mapDataID = node["tileIDSize"].as<Uint8>(serKey._mapDataID);
-		serKey._mapDataSetID = node["tileSetIDSize"].as<Uint8>(serKey._mapDataSetID);
-		serKey.boolFields = node["tileBoolFieldsSize"].as<Uint8>(1); // boolean flags used to be stored in an unmentioned byte (Uint8) :|
+		serKey._fire = node["tileFireSize"].as<char>(serKey._fire);
+		serKey._smoke = node["tileSmokeSize"].as<char>(serKey._smoke);
+		serKey._mapDataID = node["tileIDSize"].as<char>(serKey._mapDataID);
+		serKey._mapDataSetID = node["tileSetIDSize"].as<char>(serKey._mapDataSetID);
+		serKey.boolFields = node["tileBoolFieldsSize"].as<char>(1); // boolean flags used to be stored in an unmentioned byte (Uint8) :|
 
 		// load binary tile data! 
 		YAML::Binary binTiles = node["binTiles"].as<YAML::Binary>();
@@ -380,13 +380,13 @@
 	}
 #else
 	// first, write out the field sizes we're going to use to write the tile data
-	node["tileIndexSize"] = Tile::serializationKey.index;
+	node["tileIndexSize"] = static_cast<char>(Tile::serializationKey.index);
 	node["tileTotalBytesPer"] = Tile::serializationKey.totalBytes;
-	node["tileFireSize"] = Tile::serializationKey._fire;
-	node["tileSmokeSize"] = Tile::serializationKey._smoke;
-	node["tileIDSize"] = Tile::serializationKey._mapDataID;
-	node["tileSetIDSize"] = Tile::serializationKey._mapDataSetID;
-    node["tileBoolFieldsSize"] = Tile::serializationKey.boolFields;
+	node["tileFireSize"] = static_cast<char>(Tile::serializationKey._fire);
+	node["tileSmokeSize"] = static_cast<char>(Tile::serializationKey._smoke);
+	node["tileIDSize"] = static_cast<char>(Tile::serializationKey._mapDataID);
+	node["tileSetIDSize"] = static_cast<char>(Tile::serializationKey._mapDataSetID);
+	node["tileBoolFieldsSize"] = static_cast<char>(Tile::serializationKey.boolFields);
 
 	size_t tileDataSize = Tile::serializationKey.totalBytes * _mapsize_z * _mapsize_y * _mapsize_x;
 	Uint8* tileData = (Uint8*) calloc(tileDataSize, 1);
