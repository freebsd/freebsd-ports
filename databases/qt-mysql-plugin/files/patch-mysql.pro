--- plugins/src/sqldrivers/mysql/mysql.pro.orig	Wed Aug  6 13:21:58 2003
+++ plugins/src/sqldrivers/mysql/mysql.pro	Wed Aug  6 13:22:46 2003
@@ -10,6 +10,7 @@
 	!contains( LIBS, .*mysql.* ) {
 	    LIBS    *= -lmysqlclient
 	}
+	INCLUDEPATH	+= ${LOCALBASE}/include/mysql
 }
 win32 {
 	OBJECTS_DIR = obj
