--- fileservplugin/FileMetadataPipe.h.orig	2022-01-03 18:00:39 UTC
+++ fileservplugin/FileMetadataPipe.h
@@ -134,7 +134,7 @@ class FileMetadataPipe : public PipeFileBase (private)
 #include <sys/stat.h>
 #include "../common/data.h"
 
-#if defined(__APPLE__)
+#if defined(__FreeBSD__)
 void serialize_stat_buf(const struct stat& buf, const std::string& symlink_target, CWData& data);
 #else
 void serialize_stat_buf(const struct stat64& buf, const std::string& symlink_target, CWData& data);
