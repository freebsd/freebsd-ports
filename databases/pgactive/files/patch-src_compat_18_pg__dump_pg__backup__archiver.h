--- src/compat/18/pg_dump/pg_backup_archiver.h.orig	2025-10-24 11:59:50 UTC
+++ src/compat/18/pg_dump/pg_backup_archiver.h
@@ -464,7 +464,9 @@ extern void InitArchiveFmt_Tar(ArchiveHandle *AH);
 extern void InitArchiveFmt_Directory(ArchiveHandle *AH);
 extern void InitArchiveFmt_Tar(ArchiveHandle *AH);
 
+#if PG_VERSION_NUM < 180004
 extern bool isValidTarHeader(char *header);
+#endif
 
 extern void ReconnectToServer(ArchiveHandle *AH, const char *dbname);
 extern void IssueCommandPerBlob(ArchiveHandle *AH, TocEntry *te,
