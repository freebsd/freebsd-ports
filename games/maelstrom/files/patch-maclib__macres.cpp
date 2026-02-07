--- ./maclib/macres.cpp.orig	2000-01-25 17:44:20.000000000 +0100
+++ ./maclib/macres.cpp	2013-12-28 11:39:16.000000000 +0100
@@ -58,8 +58,8 @@
 				ids[j], res->ResourceName(types[i], ids[j]));
 			if ( argv[2] ) {
 				char path[23];
-				sprintf(path,"%s/%s:%hu", argv[2],
-							types[i], ids[j]);
+				snprintf(path, sizeof(path), "%s/%s:%hu",
+					argv[2], types[i], ids[j]);
 				FILE *output;
 				Mac_ResData *D;
             			if ( (output=fopen(path, "w")) != NULL ) {
