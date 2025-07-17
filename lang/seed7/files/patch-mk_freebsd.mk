--- src/mk_freebsd.mk.orig	2020-05-21 06:01:46 UTC
+++ src/mk_freebsd.mk
@@ -153,6 +153,7 @@ chkccomp.h:
 	echo "#define SQL_SERVER_LIBRARY_PATH \"-L%%LOCALBASE%%/lib\"" >> chkccomp.h
 	echo "#define TDS_INCLUDE_OPTIONS \"-I%%LOCALBASE%%/include\"" >> chkccomp.h
 	echo "#define TDS_LIBRARY_PATH \"-L%%LOCALBASE%%/lib\"" >> chkccomp.h
+	echo "#define X11_LIBRARY_PATH \"%%LOCALBASE%%/lib\"" >> chkccomp.h
 
 base.h:
 	echo "#define PATH_DELIMITER '/'" > base.h
