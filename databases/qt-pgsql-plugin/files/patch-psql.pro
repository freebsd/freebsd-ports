--- plugins/src/sqldrivers/psql/psql.pro.orig	Tue Aug  5 19:09:02 2003
+++ plugins/src/sqldrivers/psql/psql.pro	Tue Aug  5 19:09:50 2003
@@ -8,7 +8,8 @@
 	!contains( LIBS, .*pq.* ) {
 	    LIBS	*= -lpq
 	}
-}
+	INCLUDEPATH     += ${LOCALBASE}/include/postgresql/server
+	}
 
 win32 {
 	OBJECTS_DIR	= obj
