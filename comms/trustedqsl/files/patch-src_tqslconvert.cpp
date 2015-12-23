--- src/tqslconvert.cpp.orig	2015-10-21 17:26:38 UTC
+++ src/tqslconvert.cpp
@@ -549,7 +549,7 @@ static bool open_db(TQSL_CONVERTER *conv
 				fprintf(conv->errfile, "opening DB %s returns status %s\n", conv->dbpath, db_strerror(dbret));
 			// Can't open the database - maybe try private?
 			if ((dbret == EACCES || dbret == EROFS) || (dbret == EINVAL && errno == dbret)) {
-				if (!(envflags && DB_PRIVATE)) {
+				if (!(envflags & DB_PRIVATE)) {
 					envflags |= DB_PRIVATE;
 					continue;
 				}
