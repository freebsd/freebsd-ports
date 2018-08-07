--- lazpaint/ucommandline.pas	2018-04-26 00:01:03.521298000 -0500
+++ lazpaint/ucommandline.pas	2018-04-26 00:01:21.335693000 -0500
@@ -4,7 +4,7 @@
 
 interface
 
-uses classes, LazpaintType, uresourcestrings;
+uses classes, LazpaintType, uresourcestrings, LazUTF8, LazFileUtils;
 
 procedure ProcessCommands(instance: TLazPaintCustomInstance; commandsUTF8: TStringList; out errorEncountered, fileSaved: boolean);
 function ParamStrUTF8(AIndex: integer): string;
