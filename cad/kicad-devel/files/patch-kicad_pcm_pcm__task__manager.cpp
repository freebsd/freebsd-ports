--- kicad/pcm/pcm_task_manager.cpp.orig	2021-12-12 12:45:08 UTC
+++ kicad/pcm/pcm_task_manager.cpp
@@ -195,7 +195,7 @@ bool PCM_TASK_MANAGER::extract( const wxString& aFileP
     for( ; entry; entry = zip.GetNextEntry() )
     {
         wxArrayString path_parts =
-                wxSplit( entry->GetName(), wxFileName::GetPathSeparator(), (wxChar) NULL );
+                wxSplit( entry->GetName(), wxFileName::GetPathSeparator(), 0 );
 
         if( path_parts.size() < 2
             || PCM_PACKAGE_DIRECTORIES.find( path_parts[0] ) == PCM_PACKAGE_DIRECTORIES.end()
@@ -215,7 +215,7 @@ bool PCM_TASK_MANAGER::extract( const wxString& aFileP
         path_parts.Insert( clean_package_id, 1 );
         path_parts.Insert( m_pcm->Get3rdPartyPath(), 0 );
 
-        wxString fullname = wxJoin( path_parts, wxFileName::GetPathSeparator(), (wxChar) NULL );
+        wxString fullname = wxJoin( path_parts, wxFileName::GetPathSeparator(), 0 );
 
         // Ensure the target directory exists and create it if not.
         wxString t_path = wxPathOnly( fullname );
