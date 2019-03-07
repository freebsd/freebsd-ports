--- lazpaint/uclipboard.pas	2019-03-06 21:05:00.151107000 +0000
+++ lazpaint/uclipboard.pas	2019-03-06 21:05:59.844861000 +0000
@@ -473,8 +473,7 @@
     end;
 
   for i := 0 to clipboard.FormatCount-1 do
-    if (Clipboard.Formats[i] = PredefinedClipboardFormat(pcfDelphiBitmap)) or
-       (Clipboard.Formats[i] = PredefinedClipboardFormat(pcfBitmap)) then
+    if (Clipboard.Formats[i] = PredefinedClipboardFormat(pcfBitmap)) then
     begin
        Stream := TMemoryStream.Create;
        Clipboard.GetFormat(Clipboard.Formats[i],Stream);
