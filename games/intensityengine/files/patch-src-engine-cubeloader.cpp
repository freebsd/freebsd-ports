diff --git src/engine/cubeloader.cpp src/engine/cubeloader.cpp
index b7a1504..939cc2c 100755
--- src/engine/cubeloader.cpp
+++ src/engine/cubeloader.cpp
@@ -259,12 +259,12 @@ struct cubeloader
             else
             {
                 conoutf(CON_ERROR, "map %s has malformatted header", cgzname); 
-                gzclose(f); 
+                delete f;
                 return; 
             }
         }
         else if(hdr.version>5) mod = true;
-        if(hdr.version>5 && !mod) { conoutf(CON_ERROR, "map %s requires a newer version of the Cube 1 importer", cgzname); gzclose(f); return; }
+        if(hdr.version>5 && !mod) { conoutf(CON_ERROR, "map %s requires a newer version of the Cube 1 importer", cgzname); delete f; return; }
         if(!haslocalclients()) game::forceedit("");
         emptymap(12, true, NULL);
         freeocta(worldroot);
@@ -280,7 +280,7 @@ struct cubeloader
         {
             hdr.waterlevel = -100000;
         }
-        if(mod) gzseek(f, hdr.numents*sizeof(c_persistent_entity), SEEK_CUR);
+        if(mod) f->seek(hdr.numents*sizeof(c_persistent_entity), SEEK_CUR);
         else loopi(hdr.numents)
         {
             c_persistent_entity e;
