--- kicad/pcm/pcm.cpp.orig	2021-12-11 16:21:09 UTC
+++ kicad/pcm/pcm.cpp
@@ -798,7 +798,7 @@ PLUGIN_CONTENT_MANAGER::GetRepositoryPackageBitmaps( c
     for( wxArchiveEntry* entry = zip.GetNextEntry(); entry; entry = zip.GetNextEntry() )
     {
         wxArrayString path_parts =
-                wxSplit( entry->GetName(), wxFileName::GetPathSeparator(), (wxChar) NULL );
+                wxSplit( entry->GetName(), wxFileName::GetPathSeparator(), 0 );
 
         if( path_parts.size() != 2 || path_parts[1] != "icon.png" )
             continue;
