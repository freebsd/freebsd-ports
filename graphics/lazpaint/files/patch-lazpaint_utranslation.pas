--- lazpaint/utranslation.pas	2018-04-26 00:02:18.729349000 -0500
+++ lazpaint/utranslation.pas	2018-04-26 00:17:20.943460000 -0500
@@ -8,7 +8,7 @@
   {$ifdef Darwin}
   MacOSAll,
  {$endif}
-  Classes, SysUtils, UConfig, IniFiles;
+  Classes, SysUtils, UConfig, IniFiles, LazFileUtils, LazUTF8;
 
 {*************** Language ****************}
 const
@@ -62,7 +62,7 @@
       result := GetResourcesPath+'i18n'+PathDelim
     else
     {$ENDIF}
-    result:='i18n'+PathDelim;
+    result:='%%DATADIR%%'+PathDelim+'i18n'+PathDelim;
   {$ENDIF}
 end;
 
@@ -76,7 +76,7 @@
 begin
   Lang:='';
   FallbackLang:='';
-  LCLGetLanguageIDs(Lang,FallbackLang);
+  LazGetLanguageIDs(Lang,FallbackLang);
   result := FallbackLang;
 end;
 
