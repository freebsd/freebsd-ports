--- lcl/interfaces/carbon/carbonstrings.pp	2014-03-25 21:13:32.000000000 -0500
+++ lcl/interfaces/carbon/carbonstrings.pp	2014-03-25 21:15:20.000000000 -0500
@@ -18,6 +18,10 @@
 // defines
 {$I carbondefines.inc}
 
+{$if (FPC_FULLVERSION>=20701) OR (FPC_FULLVERSION>=20603)}
+{$define HAS_INHERITED_INSERTITEM}
+{$endif}
+
 uses
  // rtl+ftl
   Classes, SysUtils,
@@ -34,7 +38,7 @@
     FOwner: TCarbonComboBox;  // Carbon combo box control owning strings
   protected
     procedure Put(Index: Integer; const S: string); override;
-    {$IF FPC_FULLVERSION<20701}
+    {$IFNDEF HAS_INHERITED_INSERTITEM}
     // before fpc 2.7.1 InsertItem(Index,S) did not call InsertItem(Index,S,nil)
     procedure InsertItem(Index: Integer; const S: string); override;
     {$ENDIF}
@@ -113,7 +117,7 @@
   FOwner.Insert(Index, S);
 end;
 
-{$IF FPC_FULLVERSION<20701}
+{$IFNDEF HAS_INHERITED_INSERTITEM}
 {------------------------------------------------------------------------------
   Method:  TCarbonComboBoxStrings.InsertItem
   Params:  Index - Line index
