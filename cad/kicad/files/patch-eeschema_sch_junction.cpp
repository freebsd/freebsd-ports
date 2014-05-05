--- eeschema/sch_junction.cpp.orig	2013-03-09 21:07:56.000000000 +0100
+++ eeschema/sch_junction.cpp	2014-05-01 18:52:54.000000000 +0200
@@ -172,13 +172,13 @@
 }
 
 
-void SCH_JUNCTION::GetConnectionPoints( vector< wxPoint >& aPoints ) const
+void SCH_JUNCTION::GetConnectionPoints( std::vector< wxPoint >& aPoints ) const
 {
     aPoints.push_back( m_pos );
 }
 
 
-void SCH_JUNCTION::GetNetListItem( vector<NETLIST_OBJECT*>& aNetListItems,
+void SCH_JUNCTION::GetNetListItem( std::vector<NETLIST_OBJECT*>& aNetListItems,
                                    SCH_SHEET_PATH*          aSheetPath )
 {
     NETLIST_OBJECT* item = new NETLIST_OBJECT();
