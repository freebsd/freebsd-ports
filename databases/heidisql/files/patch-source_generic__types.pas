--- source/generic_types.pas.orig	2026-01-30 17:33:07 UTC
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
@@ -140,7 +144,11 @@ var
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
@@ -179,7 +187,11 @@ var
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
