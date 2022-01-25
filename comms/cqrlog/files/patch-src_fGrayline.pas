--- src/fGrayline.pas.orig	2021-01-16 14:03:35 UTC
+++ src/fGrayline.pas
@@ -406,7 +406,7 @@ begin
     RBNSpotList[i].band := '';
   ImageFile := dmData.HomeDir+'images'+PathDelim+'grayline.bmp';
   if not FileExists(ImageFile) then
-    ImageFile := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog'+
+    ImageFile := ExpandFileNameUTF8('%%DATADIR%%'+
                  PathDelim+'images'+PathDelim+'grayline.bmp');
   ob:=new(Pgrayline,init(ImageFile));
 
