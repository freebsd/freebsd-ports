--- src/fGrayline.pas.orig	2018-06-17 12:42:42 UTC
+++ src/fGrayline.pas
@@ -411,7 +411,7 @@ begin
     RBNSpotList[i].band := '';
   ImageFile := dmData.HomeDir+'images'+PathDelim+'grayline.bmp';
   if not FileExists(ImageFile) then
-    ImageFile := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog'+
+    ImageFile := ExpandFileNameUTF8('%%DATADIR%%'+
                  PathDelim+'images'+PathDelim+'grayline.bmp');
   ob:=new(Pgrayline,init(ImageFile))
 end;
