--- app/formmain_updates_proc.inc	2019-12-31 02:26:48.876901000 -0500
+++ app/formmain_updates_proc.inc	2019-12-31 02:27:54.060082000 -0500
@@ -132,7 +132,7 @@
 
     if F.IsBinary then
     begin
-      S:= cEncConvNames[F.Binary.TextEncoding];
+      S:= cEncConvNames[EncConvFindEncoding(F.Binary.TextEncoding)];
     end
     else
       S:= '';
