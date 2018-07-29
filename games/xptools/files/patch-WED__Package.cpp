--- src/WEDCore/WED_Package.cpp.orig	2018-07-05 05:01:58 UTC
+++ src/WEDCore/WED_Package.cpp
@@ -103,11 +103,11 @@ WED_Package::WED_Package(const char * in
 		string wed_folder = mPackageBase + EDIT_DIR_NAME + EARTH_DIR_NAME;
 		string earth_folder = mPackageBase + EARTH_DIR_NAME;
 		int err;
-		if (err = FILE_make_dir_exist(mPackageBase.c_str()))
+		if ((err = FILE_make_dir_exist(mPackageBase.c_str())) == true)
 			WED_ThrowPrintf("Unable to create directory %s: %d", mPackageBase.c_str(), err);
-		if (err = FILE_make_dir_exist(wed_folder.c_str()))
+		if ((err = FILE_make_dir_exist(wed_folder.c_str())) == true)
 			WED_ThrowPrintf("Unable to create directory %s: %d", wed_folder.c_str(), err);
-		if (err = FILE_make_dir_exist(earth_folder.c_str()))
+		if ((err = FILE_make_dir_exist(earth_folder.c_str())) == true)
 			WED_ThrowPrintf("Unable to create directory %s: %d", earth_folder.c_str(), err);
 	}
 
@@ -174,7 +174,7 @@ WED_Document *	WED_Package::OpenTile(int
 	sprintf(partial, DIR_STR "%+03d%+04d", latlon_bucket(lat),latlon_bucket(lon));
 	string parent = mPackageBase + EDIT_DIR_NAME + EARTH_DIR_NAME + partial;
 	int err;
-	if (err = FILE_make_dir_exist(parent.c_str()))
+	if ((err = FILE_make_dir_exist(parent.c_str())) == true)
 		WED_ThrowPrintf("Unable to open create %s: %d", parent.c_str(), err);
 
 	WED_Document * tile = new WED_Document(path, bounds);
