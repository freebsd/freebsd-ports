--- src/libprojectM/FileScanner.cpp.orig	2020-09-15 05:56:43 UTC
+++ src/libprojectM/FileScanner.cpp
@@ -121,7 +121,7 @@ void FileScanner::scanGeneric(ScanCallback cb, const c
 
 #ifdef HAVE_FTS_H
 // more optimized posix "fts" directory traversal
-int fts_compare(const FTSENT** one, const FTSENT** two) {
+int fts_compare(const FTSENT* const * one, const FTSENT* const * two) {
     return (strcmp((*one)->fts_name, (*two)->fts_name));
 }
 #endif
