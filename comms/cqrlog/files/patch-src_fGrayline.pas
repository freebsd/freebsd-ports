--- src/fGrayline.pas.orig	2014-07-01 00:36:18.000000000 -0700
+++ src/fGrayline.pas	2014-07-01 00:36:48.000000000 -0700
@@ -385,7 +385,7 @@
     RBNSpotList[i].band := '';
   ImageFile := dmData.HomeDir+'images'+PathDelim+'grayline.bmp';
   if not FileExists(ImageFile) then
-    ImageFile := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog'+
+    ImageFile := ExpandFileNameUTF8('%%PREFIX%%'+PathDelim+'share'+PathDelim+'cqrlog'+
                  PathDelim+'images'+PathDelim+'grayline.bmp');
   ob:=new(Pgrayline,init(ImageFile))
 end;
