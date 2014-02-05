--- ./rtengine/safegtk.cc.orig	2012-01-31 05:00:05.000000000 +0400
+++ ./rtengine/safegtk.cc	2012-03-29 19:31:25.000000000 +0400
@@ -98,7 +98,7 @@
 	Glib::RefPtr<Gio::FileEnumerator> dirList;
 	if (dir) {
 		SAFE_ENUMERATOR_CODE_START
-				flist.push_back (FileMTimeInfo (removeExtension(info->get_name()), info->modification_time()));
+				flist.push_back (FileMTimeInfo (removeExtension(info->get_display_name()), info->modification_time()));
 		SAFE_ENUMERATOR_CODE_END;
 	}
 }
@@ -113,7 +113,7 @@
 	if (dir) {
 		if (!extensions) {
 			SAFE_ENUMERATOR_CODE_START
-				names.push_back (Glib::build_filename (directory, info->get_name()));
+				names.push_back (Glib::build_filename (directory, info->get_display_name()));
 			SAFE_ENUMERATOR_CODE_END;
 		}
 		else {
@@ -124,7 +124,7 @@
 
 			SAFE_ENUMERATOR_CODE_START
 			// convert the current filename to lowercase in a new ustring
-			Glib::ustring fname = Glib::ustring(info->get_name()).lowercase();
+			Glib::ustring fname = Glib::ustring(info->get_display_name()).lowercase();
 
 			int pos = fname.find_last_of('.');
 			if (pos > -1 && pos < (fname.length()-1)) {
@@ -135,7 +135,7 @@
 				// look out if it has one of the retained extensions
 				for (unsigned int i=0; i<lcExtensions.size(); i++) {
 					if (lcFileExt == lcExtensions[i]) {
-						names.push_back (Glib::build_filename (directory, info->get_name()));
+						names.push_back (Glib::build_filename (directory, info->get_display_name()));
 						break;
 					}
 				}
@@ -156,7 +156,7 @@
 
 				SAFE_ENUMERATOR_CODE_START
 						if (info->get_file_type() == Gio::FILE_TYPE_DIRECTORY && (!info->is_hidden() || add_hidden))
-								subDirs.push_back (info->get_name());
+								subDirs.push_back (info->get_display_name());
 				SAFE_ENUMERATOR_CODE_END;
 	}
 }
