--- eeschema/sch_sheet.cpp.orig	2013-03-09 21:07:56.000000000 +0100
+++ eeschema/sch_sheet.cpp	2014-05-01 18:58:07.000000000 +0200
@@ -1000,7 +1000,7 @@
 }
 
 
-void SCH_SHEET::GetConnectionPoints( vector< wxPoint >& aPoints ) const
+void SCH_SHEET::GetConnectionPoints( std::vector< wxPoint >& aPoints ) const
 {
     for( size_t i = 0; i < GetPins().size(); i++ )
         aPoints.push_back( GetPins()[i].m_Pos );
@@ -1072,7 +1072,7 @@
 }
 
 
-void SCH_SHEET::GetNetListItem( vector<NETLIST_OBJECT*>& aNetListItems,
+void SCH_SHEET::GetNetListItem( std::vector<NETLIST_OBJECT*>& aNetListItems,
                                 SCH_SHEET_PATH*          aSheetPath )
 {
     SCH_SHEET_PATH sheetPath = *aSheetPath;
