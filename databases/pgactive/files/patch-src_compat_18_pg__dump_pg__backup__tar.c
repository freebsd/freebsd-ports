--- src/compat/18/pg_dump/pg_backup_tar.c.orig	2025-10-24 11:59:50 UTC
+++ src/compat/18/pg_dump/pg_backup_tar.c
@@ -984,6 +984,7 @@ tarPrintf(TAR_MEMBER *th, const char *fmt,...)
 	return (int) cnt;
 }
 
+#if PG_VERSION_NUM < 180004
 bool
 isValidTarHeader(char *header)
 {
@@ -1008,6 +1009,7 @@ isValidTarHeader(char *header)
 
 	return false;
 }
+#endif
 
 /* Given the member, write the TAR header & copy the file */
 static void
