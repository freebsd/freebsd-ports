--- eeschema/sch_text.cpp.orig	2013-03-09 21:07:56.000000000 +0100
+++ eeschema/sch_text.cpp	2014-05-01 18:59:57.000000000 +0200
@@ -564,7 +564,7 @@
 }
 
 
-void SCH_TEXT::GetConnectionPoints( vector< wxPoint >& aPoints ) const
+void SCH_TEXT::GetConnectionPoints( std::vector< wxPoint >& aPoints ) const
 {
     // Normal text labels do not have connection points.  All others do.
     if( Type() == SCH_TEXT_T )
@@ -613,7 +613,7 @@
 }
 
 
-void SCH_TEXT::GetNetListItem( vector<NETLIST_OBJECT*>& aNetListItems,
+void SCH_TEXT::GetNetListItem( std::vector<NETLIST_OBJECT*>& aNetListItems,
                                SCH_SHEET_PATH*          aSheetPath )
 {
     if( GetLayer() == LAYER_NOTES || GetLayer() == LAYER_SHEETLABEL )
