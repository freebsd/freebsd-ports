--- source/main.pas.orig	2026-06-09 17:25:49 UTC
+++ source/main.pas
@@ -15,9 +15,12 @@ uses
   LazStringUtils, dbconnection, dbstructures, dbstructures.mysql, generic_types,
   apphelpers, extra_controls, createdatabase, SynEditMarkup, SynEditMarkupBracket,
   searchreplace, ImgList, IniFiles, LazFileUtils, LazUTF8, tabletools,
-  lazaruscompat, extfiledialog, process, SynEditMiscClasses, Contnrs, SynExportHTML;
+  lazaruscompat, extfiledialog, process, SynEditMiscClasses, Contnrs, SynExportHTML
+{$IFDEF CPUAARCH64 AND $IFDEF FREEBSD}
+  , LazEditTextAttributes
+{$ENDIF}
+  ;
 
-
 type
 
   // Bind parameters for query tabs
@@ -7129,7 +7132,11 @@ var
   Editor: TSynMemo;
   Token: String;
   CaretStart, CaretTokenTypeInt: Integer;
+{$IFDEF CPUAARCH64 AND $IFDEF FREEBSD}
+  Attri: TLazEditTextAttribute;
+{$ELSE}
   Attri: TSynHighlighterAttributes;
+{$ENDIF}
   Proposal: TSynCompletion;
   p: TPoint;
   LineIdx, ColIdx, StartCol, EndCol: Integer;
@@ -7345,7 +7352,11 @@ var
 var
   Edit: TSynEdit;
   Token: String;
+{$IFDEF CPUAARCH64 AND $IFDEF FREEBSD}
+  Attri: TLazEditTextAttribute;
+{$ELSE}
   Attri: TSynHighlighterAttributes;
+{$ENDIF}
   TokenType, TokenStart: Integer;
   RowColPos: TPoint;
   SQLFunc: TSQLFunction;
@@ -13403,7 +13414,11 @@ var
   Editors: TComponentList;
   BaseEditor: TSynMemo;
   KeyStroke: TSynEditKeyStroke;
+{$IFDEF CPUAARCH64 AND $IFDEF FREEBSD}
+  Attri: TLazEditTextAttribute;
+{$ELSE}
   Attri: TSynHighlighterAttributes;
+{$ENDIF}
   Shortcut1, Shortcut2: TShortcut;
 begin
   // Setup all known TSynMemo's
