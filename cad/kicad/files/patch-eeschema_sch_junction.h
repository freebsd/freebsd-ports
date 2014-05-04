--- eeschema/sch_junction.h.orig	2013-03-09 21:07:56.000000000 +0100
+++ eeschema/sch_junction.h	2014-05-01 18:31:15.000000000 +0200
@@ -78,13 +78,13 @@
 
     bool IsConnectable() const { return true; }
 
-    void GetConnectionPoints( vector< wxPoint >& aPoints ) const;
+    void GetConnectionPoints( std::vector< wxPoint >& aPoints ) const;
 
     wxString GetSelectMenuText() const { return wxString( _( "Junction" ) ); }
 
     BITMAP_DEF GetMenuImage() const { return  add_junction_xpm; }
 
-    void GetNetListItem( vector<NETLIST_OBJECT*>& aNetListItems, SCH_SHEET_PATH* aSheetPath );
+    void GetNetListItem( std::vector<NETLIST_OBJECT*>& aNetListItems, SCH_SHEET_PATH* aSheetPath );
 
     wxPoint GetPosition() const { return m_pos; }
 
