--- lazpaint/utranslation.pas	2020-05-13 16:32:15.701490000 -0500
+++ lazpaint/utranslation.pas	2020-05-13 16:51:08.348905000 -0500
@@ -60,10 +60,13 @@
   {$ELSE}
     {$IFDEF DARWIN}
     if DirectoryExists(GetDarwinResourcesPath+AResource) then
-      result := GetDarwinResourcesPath+AResource+PathDelim
-    else
+      result := GetDarwinResourcesPath+AResource+PathDelim;
     {$ENDIF}
-    result:=ExtractFilePath(Application.ExeName)+AResource+PathDelim;
+    {$IFDEF FREEBSD}
+      result:='%%DATADIR%%'+PathDelim+AResource+PathDelim;
+    {$ELSE}
+      result:=ExtractFilePath(Application.ExeName)+AResource+PathDelim;
+    {$ENDIF}
   {$ENDIF}
 end;
 
