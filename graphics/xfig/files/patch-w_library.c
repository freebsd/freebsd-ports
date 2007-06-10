--- w_library.c.orig	Mon Apr  3 09:27:30 2006
+++ w_library.c
@@ -1029,6 +1029,7 @@
     Widget	     menu, entry;
 #ifndef XAW3D1_5E
     Widget	     submenu;
+#else
     char	     submenu_name[200];
 #endif /* XAW3D1_5E */
     char	     menu_name[200];
@@ -1371,7 +1372,7 @@
 	return 0;
     } else if (S_ISDIR(st.st_mode)) {
 	/* if it is directory, scan the sub-directories and search libraries */
-	(void) ScanLibraryDirectory(True, &library_rec, path, "", "", &dum, &numlibs);
+	(void) ScanLibraryDirectory(True, library_rec, path, "", "", &dum, &numlibs);
 	return numlibs;
     } else {
 	/* if it is a file, it must contain list of libraries */
