--- source/generic_types.pas.orig	2026-08-03 17:17:06 UTC
+++ source/generic_types.pas
@@ -5,7 +5,11 @@ uses fpjson, jsonparser, SysUtils, RegExpr, SynEditHig
 interface
 
 uses fpjson, jsonparser, SysUtils, RegExpr, SynEditHighlighter, SynHighlighterSQL,
-  Classes, Generics.Collections, Graphics, dbstructures;
+  Classes, Generics.Collections, Graphics, dbstructures
+{$IFDEF CPUAARCH64 AND $IFDEF FREEBSD}
+  , LazEditTextAttributes
+{$ENDIF}
+  ;
 
 type
   TThreeStateBoolean = (nbUnset, nbFalse, nbTrue);
@@ -153,7 +157,11 @@ var
 procedure TAppColorScheme.LoadFromSettings;
 var
   i: Integer;
+{$IFDEF CPUAARCH64 AND $IFDEF FREEBSD}
+  Attri: TLazEditTextAttribute;
+{$ELSE}
   Attri: TSynHighlighterAttributes;
+{$ENDIF}
   dtc: TDBDatatypeCategoryIndex;
 begin
   Name := _('Current custom settings');
@@ -192,7 +200,11 @@ var
 procedure TAppColorScheme.Apply;
 var
   i: Integer;
+{$IFDEF CPUAARCH64 AND $IFDEF FREEBSD}
+  Attri: TLazEditTextAttribute; 
+{$ELSE}
   Attri: TSynHighlighterAttributes;
+{$ENDIF}
 begin
   // Highlighter colors
   for i:=0 to SynSqlSyn.AttrCount - 1 do begin
