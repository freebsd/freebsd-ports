--- lazpaint/ugraph.pas	2018-04-26 00:33:20.456108000 -0500
+++ lazpaint/ugraph.pas	2018-04-26 00:33:27.797858000 -0500
@@ -6,7 +6,7 @@
 
 uses
   Classes, SysUtils, bgrabitmap, bgrabitmaptypes, LazPaintType, Graphics, BGRALayers, LCLType,
-  BCButton;
+  BCButton, LazUTF8;
 
 const FrameDashLength = 4;
   NicePointMaxRadius = 4;
