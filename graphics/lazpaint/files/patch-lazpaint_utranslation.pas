--- lazpaint/utranslation.pas	2021-02-18 08:49:03.053438000 -0500
+++ lazpatin/utranslation.pas	2021-02-18 09:04:38.021589000 -0500
@@ -85,7 +85,11 @@
       else
       {$ENDIF}
     {$ENDIF}
-    result:=ExtractFilePath(Application.ExeName)+AResource+PathDelim;
+    {$IFDEF FREEBSD}
+      result:='%%DATADIR%%'+PathDelim+AResource+PathDelim;
+    {$ELSE}
+      result:=ExtractFilePath(Application.ExeName)+AResource+PathDelim;
+    {$ENDIF}
   {$ENDIF}
 end;
 
