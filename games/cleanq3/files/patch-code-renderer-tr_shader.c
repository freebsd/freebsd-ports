--- ./code/renderer/tr_shader.c.orig	Wed May 31 20:52:08 2006
+++ ./code/renderer/tr_shader.c	Wed May 31 20:56:20 2006
@@ -99,7 +99,7 @@
 
 	// remap all the shaders with the given name
 	// even tho they might have different lightmaps
-	COM_StripExtension( shaderName, strippedName );
+	COM_StripExtension( shaderName, strippedName, sizeof(strippedName) );
 	hash = generateHashValue(strippedName, FILE_HASH_SIZE);
 	for (sh = hashTable[hash]; sh; sh = sh->next) {
 		if (Q_stricmp(sh->name, strippedName) == 0) {
@@ -2368,7 +2368,7 @@
 		return tr.defaultShader;
 	}
 
-	COM_StripExtension( name, strippedName );
+	COM_StripExtension( name, strippedName, sizeof(strippedName) );
 
 	hash = generateHashValue(strippedName, FILE_HASH_SIZE);
 
@@ -2436,7 +2436,7 @@
 		lightmapIndex = LIGHTMAP_BY_VERTEX;
 	}
 
-	COM_StripExtension( name, strippedName );
+	COM_StripExtension( name, strippedName, sizeof(strippedName) );
 
 	hash = generateHashValue(strippedName, FILE_HASH_SIZE);
 
