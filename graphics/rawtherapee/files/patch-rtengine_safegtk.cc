--- rtengine/safegtk.cc.orig	2017-01-14 17:35:18 UTC
+++ rtengine/safegtk.cc
@@ -184,7 +184,7 @@ void safe_build_file_list (Glib::RefPtr<
 	Glib::RefPtr<Gio::FileEnumerator> dirList;
 	if (dir) {
 		SAFE_ENUMERATOR_CODE_START
-				flist.push_back (FileMTimeInfo (removeExtension(info->get_name()), info->modification_time()));
+				flist.push_back (FileMTimeInfo (removeExtension(info->get_display_name()), info->modification_time()));
 		SAFE_ENUMERATOR_CODE_END;
 	}
 }
@@ -199,7 +199,7 @@ void safe_build_file_list (Glib::RefPtr<
 	if (dir) {
 		if (!extensions) {
 			SAFE_ENUMERATOR_CODE_START
-				names.push_back (Glib::build_filename (directory, info->get_name()));
+				names.push_back (Glib::build_filename (directory, info->get_display_name()));
 			SAFE_ENUMERATOR_CODE_END;
 		}
 		else {
@@ -210,7 +210,7 @@ void safe_build_file_list (Glib::RefPtr<
 
 			SAFE_ENUMERATOR_CODE_START
 			// convert the current filename to lowercase in a new ustring
-			Glib::ustring fname = Glib::ustring(info->get_name()).lowercase();
+			Glib::ustring fname = Glib::ustring(info->get_display_name()).lowercase();
 
 			size_t pos = fname.find_last_of('.');
 			if (pos < (fname.length()-1)) {
@@ -221,7 +221,7 @@ void safe_build_file_list (Glib::RefPtr<
 				// look out if it has one of the retained extensions
 				for (size_t i=0; i<lcExtensions.size(); i++) {
 					if (lcFileExt == lcExtensions[i]) {
-						names.push_back (Glib::build_filename (directory, info->get_name()));
+						names.push_back (Glib::build_filename (directory, info->get_display_name()));
 						break;
 					}
 				}
@@ -242,7 +242,7 @@ void safe_build_subdir_list (Glib::RefPt
 
 				SAFE_ENUMERATOR_CODE_START
 						if (info->get_file_type() == Gio::FILE_TYPE_DIRECTORY && (!info->is_hidden() || add_hidden))
-								subDirs.push_back (info->get_name());
+								subDirs.push_back (info->get_display_name());
 				SAFE_ENUMERATOR_CODE_END;
 	}
 }
