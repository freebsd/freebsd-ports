--- ./controls.cpp.orig	2001-03-24 19:04:28.000000000 +0100
+++ ./controls.cpp	2013-12-28 11:39:15.000000000 +0100
@@ -83,7 +83,7 @@
 	if ( fname ) {
 		*fname = datafile;
 	}
-	sprintf(datafile,  "%s"DIR_SEP"%s", home, MAELSTROM_DATA);
+	snprintf(datafile, sizeof(datafile), "%s"DIR_SEP"%s", home, MAELSTROM_DATA);
 	if ( (data=fopen(datafile, mode)) == NULL )
 		return(NULL);
 	return(data);
