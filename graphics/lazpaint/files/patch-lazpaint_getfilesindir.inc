--- lazpaint/getfilesindir.inc.orig	2026-08-18 21:04:48 UTC
+++ lazpaint/getfilesindir.inc
@@ -56,7 +56,7 @@ var
   MaskList: TMaskList = nil;
   Files: TList;
   FileItem: TFileItem;
-  MaskOptions: TMaskOptions;
+  MaskOptions: TMaskOpCodes;
   {$if defined(windows) and not defined(wince)}
   ErrMode : LongWord;
   {$endif}
@@ -86,15 +86,8 @@ begin
       //this behaviour would be incompatible with the situation if no MaskList was used
       //and it would break backwards compatibilty and could raise unexpected EConvertError where it did not in the past.
       //If you need sets in the MaskList, use the OnAddItem event for that. (BB)
-      MaskOptions := [moDisableSets];
-      {$ifdef NotLiteralFilenames}
-      if (ACaseSensitivity = mcsCaseSensitive) then
-        MaskOptions := [moDisableSets, moCaseSensitive];
-      {$else}
-      if (ACaseSensitivity <> mcsCaseInsensitive) then
-        MaskOptions := [moDisableSets, moCaseSensitive];
-      {$endif}
-      MaskList := TMaskList.Create(AMask, ';', MaskOptions);  //False by default
+      MaskOptions := MaskOpCodesDisableRange;
+      MaskList := TMaskList.Create(AMask, ';', True, MaskOptions);  //False by default
     end;
 
     try
