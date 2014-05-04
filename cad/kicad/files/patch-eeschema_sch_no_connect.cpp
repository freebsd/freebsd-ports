--- eeschema/sch_no_connect.cpp.orig	2013-03-09 21:07:56.000000000 +0100
+++ eeschema/sch_no_connect.cpp	2014-05-01 18:56:25.000000000 +0200
@@ -182,13 +182,13 @@
 }
 
 
-void SCH_NO_CONNECT::GetConnectionPoints( vector< wxPoint >& aPoints ) const
+void SCH_NO_CONNECT::GetConnectionPoints( std::vector< wxPoint >& aPoints ) const
 {
     aPoints.push_back( m_pos );
 }
 
 
-void SCH_NO_CONNECT::GetNetListItem( vector<NETLIST_OBJECT*>& aNetListItems,
+void SCH_NO_CONNECT::GetNetListItem( std::vector<NETLIST_OBJECT*>& aNetListItems,
                                      SCH_SHEET_PATH*          aSheetPath )
 {
     NETLIST_OBJECT* item = new NETLIST_OBJECT();
