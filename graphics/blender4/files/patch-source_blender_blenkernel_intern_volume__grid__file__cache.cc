-- fix for openvdb-14.0.0

--- source/blender/blenkernel/intern/volume_grid_file_cache.cc.orig	2026-11-01 00:59:41 UTC
+++ source/blender/blenkernel/intern/volume_grid_file_cache.cc
@@ -92,7 +92,7 @@ static FileCache create_file_cache(const StringRef fil
 #  ifdef OPENVDB_USE_DELAYED_LOADING
     file.setCopyMaxBytes(0);
 #  endif
-    file.open(delay_load);
+    file.open(/*delay_load*/);
     vdb_grids = *(file.readAllGridMetadata());
     file_cache.meta_data = *file.getMetadata();
   }
@@ -190,7 +190,7 @@ static openvdb::GridBase::Ptr load_single_grid_from_di
 #  ifdef OPENVDB_USE_DELAYED_LOADING
   file.setCopyMaxBytes(0);
 #  endif
-  file.open(delay_load);
+  file.open(/*delay_load*/);
   return file.readGrid(grid_name);
 }
 
