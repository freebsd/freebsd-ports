--- eeschema/sch_component.cpp.orig	2013-03-09 21:07:56.000000000 +0100
+++ eeschema/sch_component.cpp	2014-05-01 18:45:07.000000000 +0200
@@ -1622,7 +1622,7 @@
 }
 
 
-void SCH_COMPONENT::GetConnectionPoints( vector< wxPoint >& aPoints ) const
+void SCH_COMPONENT::GetConnectionPoints( std::vector< wxPoint >& aPoints ) const
 {
     LIB_PIN* pin;
     LIB_COMPONENT* component = CMP_LIBRARY::FindLibraryComponent( m_ChipName );
@@ -1738,7 +1738,7 @@
 }
 
 
-void SCH_COMPONENT::GetNetListItem( vector<NETLIST_OBJECT*>& aNetListItems,
+void SCH_COMPONENT::GetNetListItem( std::vector<NETLIST_OBJECT*>& aNetListItems,
                                     SCH_SHEET_PATH*          aSheetPath )
 {
     LIB_COMPONENT* component = CMP_LIBRARY::FindLibraryComponent( GetLibName() );
@@ -1893,7 +1893,7 @@
 
 bool SCH_COMPONENT::doIsConnected( const wxPoint& aPosition ) const
 {
-    vector< wxPoint > pts;
+    std::vector< wxPoint > pts;
 
     GetConnectionPoints( pts );
 
