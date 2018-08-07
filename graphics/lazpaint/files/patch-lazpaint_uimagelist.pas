--- lazpaint/uimagelist.pas	2018-04-25 23:59:46.369724000 -0500
+++ lazpaint/uimagelist.pas	2018-04-26 00:00:08.521184000 -0500
@@ -7,7 +7,7 @@
 
 uses
   Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs,
-  Grids, StdCtrls, Buttons, ComCtrls, ExtCtrls, Menus,
+  Grids, StdCtrls, Buttons, ComCtrls, ExtCtrls, Menus, LazFileUtils,
   LazPaintType, UResourceStrings, UConfig, BGRAImageList, ubrowseimages;
 
 type
