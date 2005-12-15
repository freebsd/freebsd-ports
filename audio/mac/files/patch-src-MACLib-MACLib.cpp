--- src/MACLib/MACLib.cpp.orig	Wed May  4 15:35:33 2005
+++ src/MACLib/MACLib.cpp	Mon Nov 28 01:45:59 2005
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
