--- source/customize_highlighter.pas.orig	2026-01-30 17:33:07 UTC
+++ source/customize_highlighter.pas
@@ -7,7 +7,11 @@ uses
 uses
   SysUtils, Variants, Classes, Graphics, EditBtn,
   Controls, Forms, Dialogs, StdCtrls, ExtCtrls,
-  StrUtils, SynEditHighlighter, apphelpers, extra_controls;
+  StrUtils, SynEditHighlighter, apphelpers, extra_controls
+{$IFDEF CPUAARCH64 AND $IFDEF FREEBSD}
+  , LazEditTextAttributes
+{$endif}
+;
 
 type
   TfrmCustomizeHighlighter = class(TExtForm)
@@ -34,7 +38,11 @@ type
   private
     { Private-Deklarationen }
     FHighlighter: TSynCustomHighlighter;
+{$IFDEF CPUAARCH64 AND $IFDEF FREEBSD}
+    FAttr: TLazEditTextAttribute;
+{$ELSE}
     FAttr: TSynHighlighterAttributes;
+{$ENDIF}
     FOnChange: TNotifyEvent;
     procedure SetFriendlyLanguageName(FriendlyLanguageName: String);
     function GetFriendlyLanguageName: String;
