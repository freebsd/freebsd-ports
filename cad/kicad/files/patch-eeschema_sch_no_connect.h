--- eeschema/sch_no_connect.h.orig	2013-03-09 21:07:56.000000000 +0100
+++ eeschema/sch_no_connect.h	2014-05-01 18:25:21.000000000 +0200
@@ -80,13 +80,13 @@
 
     bool IsConnectable() const { return true; }
 
-    void GetConnectionPoints( vector< wxPoint >& aPoints ) const;
+    void GetConnectionPoints( std::vector< wxPoint >& aPoints ) const;
 
     wxString GetSelectMenuText() const { return wxString( _( "No Connect" ) ); }
 
     BITMAP_DEF GetMenuImage() const { return noconn_xpm; }
 
-    void GetNetListItem( vector<NETLIST_OBJECT*>& aNetListItems, SCH_SHEET_PATH* aSheetPath );
+    void GetNetListItem( std::vector<NETLIST_OBJECT*>& aNetListItems, SCH_SHEET_PATH* aSheetPath );
 
     wxPoint GetPosition() const { return m_pos; }
 
