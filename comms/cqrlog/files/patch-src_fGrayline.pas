--- src/fGrayline.pas.orig	2016-05-07 08:21:24 UTC
+++ src/fGrayline.pas
@@ -383,7 +383,7 @@ begin
     RBNSpotList[i].band := '';
   ImageFile := dmData.HomeDir+'images'+PathDelim+'grayline.bmp';
   if not FileExists(ImageFile) then
-    ImageFile := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog'+
+    ImageFile := ExpandFileNameUTF8('%%DATADIR%%'+
                  PathDelim+'images'+PathDelim+'grayline.bmp');
   ob:=new(Pgrayline,init(ImageFile))
 end;
