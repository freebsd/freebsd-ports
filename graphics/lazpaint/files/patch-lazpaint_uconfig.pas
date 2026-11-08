--- lazpaint/uconfig.pas.orig	2026-08-18 19:34:32 UTC
+++ lazpaint/uconfig.pas
@@ -371,7 +371,7 @@ implementation
 
 implementation
 
-uses uparse, LCLProc, BGRAUTF8, LazFileUtils, UFileSystem, UDarkTheme;
+uses uparse, LCLProc, BGRAUTF8, LazFileUtils, UFileSystem, UDarkTheme, GraphMath;
 
 const maxRecentFiles = 10;
       maxRecentDirectories = 10;
@@ -1841,7 +1841,7 @@ begin
 begin
   currentScreenSize := rect(0,0,screen.Width,screen.Height);
   previousScreenSize := DefaultScreenSize;
-  if not CompareRect(@previousScreenSize,@currentScreenSize.left) then
+  if not SameRect(@previousScreenSize,@currentScreenSize.left) then
   begin
     SetDefaultScreenSize(currentScreenSize);
     result := true;
