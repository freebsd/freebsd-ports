--- eeschema/sch_line.cpp.orig	2013-03-09 21:07:56.000000000 +0100
+++ eeschema/sch_line.cpp	2014-05-01 18:54:48.000000000 +0200
@@ -467,7 +467,7 @@
 }
 
 
-void SCH_LINE::GetConnectionPoints( vector< wxPoint >& aPoints ) const
+void SCH_LINE::GetConnectionPoints( std::vector< wxPoint >& aPoints ) const
 {
     aPoints.push_back( m_start );
     aPoints.push_back( m_end );
@@ -522,7 +522,7 @@
 }
 
 
-void SCH_LINE::GetNetListItem( vector<NETLIST_OBJECT*>& aNetListItems,
+void SCH_LINE::GetNetListItem( std::vector<NETLIST_OBJECT*>& aNetListItems,
                                SCH_SHEET_PATH*          aSheetPath )
 {
     // Net list item not required for graphic lines.
