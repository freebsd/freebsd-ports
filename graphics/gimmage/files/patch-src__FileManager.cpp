--- src/FileManager.cpp.orig	2007-06-26 13:51:15 UTC
+++ src/FileManager.cpp
@@ -23,12 +23,13 @@ Copyright 2006 Bartek Kostrzewa
 
 #include "FileManager.h"
 #include "defines.h"
+#define get_current_dir_name() getcwd(NULL, PATH_MAX)
 
 #include "../config.h"
 
 extern "C" {
 #include <libintl.h>
-// #include <unistd.h>
+#include <unistd.h>
 #include <sys/stat.h>
 }
 
@@ -378,7 +379,7 @@ Glib::ustring FileManager::get_previous_file()
 	// OR
 	// we've hit the first picture going forwards and now want to go backwards
 	// we display the last picture
-	if( last_op_previous && file_iterator == begin || last_op_next && file_iterator == begin )
+	if( (last_op_previous && file_iterator == begin) || (last_op_next && file_iterator == begin) )
 		{
 		last_op_previous = true;
 		last_op_next = false;
@@ -466,7 +467,7 @@ bool FileManager::filter_filename(Glib::ustring filena
 		result.find("PCX") != Glib::ustring::npos ||
 		result.find("PGM") != Glib::ustring::npos	||
 		result.find("PPM") != Glib::ustring::npos	||
-		result.find("TIFF") != Glib::ustring::npos && result.find("EPS") == Glib::ustring::npos	||
+		result.find("TIFF") != Glib::ustring::npos & result.find("EPS") == Glib::ustring::npos	||
 		result.find("X pixmap image text") != Glib::ustring::npos	||
 		result.find("Targa") != Glib::ustring::npos	||
 		result.find("PBM") != Glib::ustring::npos	||
