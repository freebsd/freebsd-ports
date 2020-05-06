--- mk_freebsd.mk.orig	2020-04-15 07:58:59.000000000 +0000
+++ mk_freebsd.mk	2020-05-06 10:16:02.032695000 +0000
@@ -154,6 +154,7 @@
 	echo "#define SQL_SERVER_LIBRARY_PATH \"-L%%LOCALBASE%%/lib\"" >> chkccomp.h
 	echo "#define TDS_INCLUDE_OPTIONS \"-I%%LOCALBASE%%/include\"" >> chkccomp.h
 	echo "#define TDS_LIBRARY_PATH \"-L%%LOCALBASE%%/lib\"" >> chkccomp.h
+	echo "#define X11_LIBRARY_PATH \"%%LOCALBASE%%/lib\"" >> chkccomp.h
 
 version.h: chkccomp.h
 	echo "#define PATH_DELIMITER '/'" > version.h
