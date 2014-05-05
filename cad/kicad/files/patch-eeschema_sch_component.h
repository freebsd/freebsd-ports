--- eeschema/sch_component.h.orig	2013-03-09 21:07:56.000000000 +0100
+++ eeschema/sch_component.h	2014-05-01 18:17:42.000000000 +0200
@@ -350,7 +350,7 @@
 
     bool IsConnectable() const { return true; }
 
-    void GetConnectionPoints( vector< wxPoint >& aPoints ) const;
+    void GetConnectionPoints( std::vector< wxPoint >& aPoints ) const;
 
     SEARCH_RESULT Visit( INSPECTOR* inspector, const void* testData,
                                  const KICAD_T scanTypes[] );
@@ -369,7 +369,7 @@
 
     BITMAP_DEF GetMenuImage() const { return  add_component_xpm; }
 
-    void GetNetListItem( vector<NETLIST_OBJECT*>& aNetListItems,
+    void GetNetListItem( std::vector<NETLIST_OBJECT*>& aNetListItems,
                                  SCH_SHEET_PATH*          aSheetPath );
 
     bool operator <( const SCH_ITEM& aItem ) const;
