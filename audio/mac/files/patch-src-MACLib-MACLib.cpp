--- src/MACLib/MACLib.cpp.orig	Wed May 12 08:56:22 2004
+++ src/MACLib/MACLib.cpp	Mon Aug  9 20:27:19 2004
@@ -62,7 +62,7 @@
         pExtension--;
 
     // take the appropriate action (based on the extension)
-    if (wcsicmp(pExtension, L".apl") == 0)
+    if (wcscmp(pExtension, L".apl") == 0)
     {
         // "link" file (.apl linked large APE file)
         CAPELink APELink(pFilename);
@@ -72,7 +72,7 @@
             nStartBlock = APELink.GetStartBlock(); nFinishBlock = APELink.GetFinishBlock();
         }
     }
-    else if ((wcsicmp(pExtension, L".mac") == 0) || (wcsicmp(pExtension, L".ape") == 0))
+    else if ((wcscmp(pExtension, L".mac") == 0) || (wcscmp(pExtension, L".ape") == 0))
     {
         // plain .ape file
         pAPEInfo = new CAPEInfo(&nErrorCode, pFilename);
