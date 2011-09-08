--- rtengine/safegtk.cc.orig	2011-09-07 14:24:33.000000000 -0700
+++ rtengine/safegtk.cc	2011-09-07 14:25:11.000000000 -0700
@@ -101,7 +101,7 @@
     Glib::RefPtr<Gio::FileEnumerator> dirList;
     if (dir) {
 				SAFE_ENUMERATOR_CODE_START
-						flist.push_back (FileMTimeInfo (removeExtension(info->get_name()), info->modification_time()));
+						flist.push_back (FileMTimeInfo (removeExtension(info->get_display_name()), info->modification_time()));
 				SAFE_ENUMERATOR_CODE_END;
     }
 }
@@ -116,7 +116,7 @@
     if (dir) {
     	if (!extensions) {
 			SAFE_ENUMERATOR_CODE_START
-				names.push_back (Glib::build_filename (directory, info->get_name()));
+				names.push_back (Glib::build_filename (directory, info->get_display_name()));
 			SAFE_ENUMERATOR_CODE_END;
     	}
     	else {
@@ -127,7 +127,7 @@
 
 			SAFE_ENUMERATOR_CODE_START
 			// convert the current filename to lowercase in a new ustring
-			Glib::ustring fname = Glib::ustring(info->get_name()).lowercase();
+			Glib::ustring fname = Glib::ustring(info->get_display_name()).lowercase();
 
 			int pos = fname.find_last_of('.');
 			if (pos > -1 && pos < (fname.length()-1)) {
@@ -138,7 +138,7 @@
 				// look out if it has one of the retained extensions
 				for (unsigned int i=0; i<lcExtensions.size(); i++) {
 					if (lcFileExt == lcExtensions[i]) {
-						names.push_back (Glib::build_filename (directory, info->get_name()));
+						names.push_back (Glib::build_filename (directory, info->get_display_name()));
 						break;
 					}
 				}
@@ -159,7 +159,7 @@
 
 				SAFE_ENUMERATOR_CODE_START
 						if (info->get_file_type() == Gio::FILE_TYPE_DIRECTORY && (!info->is_hidden() || add_hidden))
-								subDirs.push_back (info->get_name());
+								subDirs.push_back (info->get_display_name());
 				SAFE_ENUMERATOR_CODE_END;
     }
 }
