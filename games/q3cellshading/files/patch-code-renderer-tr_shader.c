--- ./code/renderer/tr_shader.c.orig	Wed May 31 18:55:11 2006
+++ ./code/renderer/tr_shader.c	Wed May 31 19:09:58 2006
@@ -92,7 +92,7 @@
 
 	// remap all the shaders with the given name
 	// even tho they might have different lightmaps
-	COM_StripExtension( shaderName, strippedName );
+	COM_StripExtension( shaderName, strippedName, sizeof(strippedName));
 	hash = generateHashValue(strippedName, FILE_HASH_SIZE);
 	for (sh = hashTable[hash]; sh; sh = sh->next) {
 		if (Q_stricmp(sh->name, strippedName) == 0) {
@@ -2351,7 +2351,7 @@
 		return tr.defaultShader;
 	}
 
-	COM_StripExtension( name, strippedName );
+	COM_StripExtension( name, strippedName, sizeof(strippedName) );
 
 	hash = generateHashValue(strippedName, FILE_HASH_SIZE);
 
@@ -2419,7 +2419,7 @@
 		lightmapIndex = LIGHTMAP_BY_VERTEX;
 	}
 
-	COM_StripExtension( name, strippedName );
+	COM_StripExtension( name, strippedName, sizeof(strippedName) );
 
 	hash = generateHashValue(strippedName, FILE_HASH_SIZE);
 
