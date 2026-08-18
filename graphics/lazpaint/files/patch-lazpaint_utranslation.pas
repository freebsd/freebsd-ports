--- lazpaint/utranslation.pas.orig	2026-08-18 19:05:41 UTC
+++ lazpaint/utranslation.pas
@@ -85,7 +85,11 @@ begin
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
 
@@ -164,12 +168,10 @@ function FallbackLanguage: string;
 end;
 
 function FallbackLanguage: string;
-var Lang,FallbackLang: string;
+var LanguageInfo: TLanguageID;
 begin
-  Lang:='';
-  FallbackLang:='';
-  LazGetLanguageIDs(Lang,FallbackLang);
-  result := FallbackLang;
+  LanguageInfo := GetLanguageID;
+  result := LanguageInfo.LanguageCode;
 end;
 
 //translate program
