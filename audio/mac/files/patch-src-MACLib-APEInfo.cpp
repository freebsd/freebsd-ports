--- src/MACLib/APEInfo.cpp.orig	Wed May 12 08:07:13 2004
+++ src/MACLib/APEInfo.cpp	Mon Aug  9 20:25:20 2004
@@ -40,7 +40,7 @@
         // we don't want to analyze right away for non-local files
         // since a single I/O object is shared, we can't tag and read at the same time (i.e. in multiple threads)
         BOOL bAnalyzeNow = TRUE;
-        if ((wcsnicmp(pFilename, L"http://", 7) == 0) || (wcsnicmp(pFilename, L"m01p://", 7) == 0))
+        if ((wcsncmp(pFilename, L"http://", 7) == 0) || (wcsncmp(pFilename, L"m01p://", 7) == 0))
             bAnalyzeNow = FALSE;
 
         m_spAPETag.Assign(new CAPETag(m_spIO, bAnalyzeNow));
