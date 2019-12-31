--- lazpaint/utranslation.pas	2019-12-30 23:16:40.903045000 -0500
+++ lazpaint/utranslation.pas	2019-12-30 23:26:13.503822000 -0500
@@ -60,10 +60,13 @@
   {$ELSE}
     {$IFDEF DARWIN}
     if DirectoryExists(GetResourcesPath+'i18n') then
-      result := GetResourcesPath+'i18n'+PathDelim
-    else
+      result := GetResourcesPath+'i18n'+PathDelim;
     {$ENDIF}
-    result:=ExtractFilePath(Application.ExeName)+'i18n'+PathDelim;
+    {$IFDEF FREEBSD}
+      result:='%%DATADIR%%'+PathDelim+'i18n'+PathDelim;
+    {$ELSE}
+      result:=ExtractFilePath(Application.ExeName)+'i18n'+PathDelim;
+    {$ENDIF}
   {$ENDIF}
 end;
 
