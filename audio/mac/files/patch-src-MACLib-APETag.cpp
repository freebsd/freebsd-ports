--- src/MACLib/APETag.cpp.orig	Wed May 12 08:10:49 2004
+++ src/MACLib/APETag.cpp	Mon Aug  9 20:26:04 2004
@@ -310,7 +310,7 @@
 
     for (int z = 0; z < m_nFields; z++)
     {
-        if (wcsicmp(m_aryFields[z]->GetFieldName(), pFieldName) == 0)
+        if (wcscmp(m_aryFields[z]->GetFieldName(), pFieldName) == 0)
             return z;
     }
 
@@ -478,7 +478,7 @@
     BOOL bFound = FALSE;
     while ((nGenreIndex < GENRE_COUNT) && (bFound == FALSE))
     {
-        if (_wcsicmp(cBuffer, g_ID3Genre[nGenreIndex]) == 0)
+        if (wcscmp(cBuffer, g_ID3Genre[nGenreIndex]) == 0)
         {
             pID3Tag->Genre = nGenreIndex;
             bFound = TRUE;
