--- lazpaint/uonline.pas	2018-04-26 00:04:51.587890000 -0500
+++ lazpaint/uonline.pas	2018-04-26 00:05:12.232466000 -0500
@@ -6,7 +6,7 @@
 
 uses
   fphttpclient, Classes, SysUtils,
-  UConfig, LazPaintType;
+  UConfig, LazPaintType, LazFileUtils;
 
 type
   { THttpGetThread }
