--- src/manager.cpp.orig	Thu Nov 29 04:30:28 2001
+++ src/manager.cpp	Thu Nov 29 04:30:40 2001
@@ -171,7 +171,7 @@
         cat.GetStatistics(&all, &fuzzy, &untranslated);
         modtime = wxFileModificationTime(file);
         lastmodified = cat.Header().RevisionDate;
-        cfg->Write(key + _T("timestamp"), modtime);
+        cfg->Write(key + _T("timestamp"), (long)modtime);
         cfg->Write(key + _T("all"), (long)all);
         cfg->Write(key + _T("fuzzy"), (long)fuzzy);
         cfg->Write(key + _T("untranslated"), (long)untranslated);
