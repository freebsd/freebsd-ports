--- eeschema/sch_sheet.h.orig	2013-03-09 21:07:56.000000000 +0100
+++ eeschema/sch_sheet.h	2014-05-01 18:23:35.000000000 +0200
@@ -532,7 +532,7 @@
 
     bool IsConnectable() const { return true; }
 
-    void GetConnectionPoints( vector< wxPoint >& aPoints ) const;
+    void GetConnectionPoints(std::vector< wxPoint >& aPoints ) const;
 
     SEARCH_RESULT Visit( INSPECTOR* inspector, const void* testData,
                                  const KICAD_T scanTypes[] );
@@ -541,7 +541,7 @@
 
     BITMAP_DEF GetMenuImage() const { return add_hierarchical_subsheet_xpm; }
 
-    void GetNetListItem( vector<NETLIST_OBJECT*>& aNetListItems,
+    void GetNetListItem( std::vector<NETLIST_OBJECT*>& aNetListItems,
                                  SCH_SHEET_PATH*          aSheetPath );
 
     SCH_ITEM& operator=( const SCH_ITEM& aSheet );
