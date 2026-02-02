--- source/preferences.pas.orig	2026-01-30 17:33:07 UTC
+++ source/preferences.pas
@@ -15,7 +15,11 @@ uses
   SynEdit, laz.VirtualTrees, SynEditKeyCmds, ActnList, Menus,
   dbstructures, RegExpr, EditBtn, LCLType, StrUtils,
   extra_controls, reformatter, Buttons, ColorBox, LCLProc, LCLIntf, lazaruscompat, FileUtil,
-  vktable, generic_types;
+  vktable, generic_types
+{$IFDEF CPUAARCH64 AND $IFDEF FREEBSD}
+  , LazEditTextAttributes
+{$ENDIF}
+  ;
 
 type
   TShortcutItemData = record
@@ -554,7 +558,11 @@ begin
     ')';
   SynSQLSynSQLSample.TableNames.CommaText := 'tableA,tableB';
   for i:=0 to SynSQLSynSQLSample.AttrCount - 1 do begin
+{$IFDEF CPUAARCH64 AND $IFDEF FREEBSD}
+    SynSQLSynSQLSample.Attribute[i].Assign(FAppColorScheme.SynSqlSyn.Attribute[i]);
+{$ELSE}
     SynSQLSynSQLSample.Attribute[i].AssignColorAndStyle(FAppColorScheme.SynSqlSyn.Attribute[i]);
+{$ENDIF}
     comboSQLColElement.Items.Add(SynSQLSynSQLSample.Attribute[i].Name);
   end;
   comboSQLColElement.Items.Add(_('Active line background'));
@@ -748,7 +756,11 @@ var
 procedure TfrmPreferences.SQLFontChange(Sender: TObject);
 var
   AttriIdx: Integer;
-  Attri: TSynHighlighterAttributes;
+{$IFDEF CPUAARCH64 AND $IFDEF FREEBSD}
+  Attri: TLazEditTextAttribute;
+{$ELSE}
+   Attri: TSynHighlighterAttributes;
+{$ENDIF}
   Foreground, Background: TColor;
 begin
   if comboSQLFontName.ItemIndex > -1 then
@@ -890,8 +902,13 @@ begin
   // Color preset selected
   ColorScheme := AppColorSchemes[comboEditorColorsPreset.ItemIndex];
   for j:=0 to SynSQLSynSQLSample.AttrCount - 1 do begin
+{$IFDEF CPUAARCH64 AND $IFDEF FREEBSD}
+    SynSQLSynSQLSample.Attribute[j].Assign(ColorScheme.SynSqlSyn.Attribute[j]);
+    FAppColorScheme.SynSqlSyn.Attribute[j].Assign(ColorScheme.SynSqlSyn.Attribute[j]);
+{$ELSE}
     SynSQLSynSQLSample.Attribute[j].AssignColorAndStyle(ColorScheme.SynSqlSyn.Attribute[j]);
     FAppColorScheme.SynSqlSyn.Attribute[j].AssignColorAndStyle(ColorScheme.SynSqlSyn.Attribute[j]);
+{$ENDIF}
   end;
   SynMemoSQLSample.LineHighlightColor.Background := ColorScheme.ActiveLineBackground;
   SynMemoSQLSample.BracketMatchColor.Foreground := ColorScheme.MatchingBraceForeground;
@@ -952,7 +969,11 @@ var
 procedure TfrmPreferences.comboSQLColElementChange(Sender: TObject);
 var
   AttriIdx: Integer;
+{$IFDEF CPUAARCH64 AND $IFDEF FREEBSD}
+  Attri: TLazEditTextAttribute;
+{$ELSE}
   Attri: TSynHighlighterAttributes;
+{$ENDIF}
   Foreground, Background: TColor;
 begin
   AttriIdx := comboSQLColElement.ItemIndex;
@@ -997,7 +1018,11 @@ var
 procedure TfrmPreferences.SynMemoSQLSampleClick(Sender: TObject);
 var
   Token: String;
+{$IFDEF CPUAARCH64 AND $IFDEF FREEBSD}
+  Attri: TLazEditTextAttribute;
+{$ELSE}
   Attri: TSynHighlighterAttributes;
+{$ENDIF}
   AttriIdx: Integer;
   sm: TSynEdit;
 begin
