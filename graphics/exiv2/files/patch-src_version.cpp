This patch fixes a crash when the procstat_getfiles()
return list contains non-vnodes that don't have an fs_path.

filed as https://github.com/Exiv2/exiv2/pull/2672

--- src/version.cpp.orig	2023-05-08 16:01:13 UTC
+++ src/version.cpp
@@ -148,7 +148,7 @@ static std::vector<std::string> getLoadedLibraries() {
     struct filestat_list* files = procs ? procstat_getfiles(procstat, procs, true) : nullptr;
     if (files) {
       filestat* entry;
-      STAILQ_FOREACH(entry, files, next) {
+      STAILQ_FOREACH(entry, files, next) if (entry && PS_FST_TYPE_VNODE == entry->fs_type && entry->fs_path) {
         std::string path(entry->fs_path);
         pushPath(path, libs, paths);
       }
