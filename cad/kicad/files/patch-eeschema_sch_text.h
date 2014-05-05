--- eeschema/sch_text.h.orig	2013-03-09 21:07:56.000000000 +0100
+++ eeschema/sch_text.h	2014-05-01 18:27:31.000000000 +0200
@@ -188,7 +188,7 @@
 
     virtual bool IsSelectStateChanged( const wxRect& aRect );
 
-    virtual void GetConnectionPoints( vector< wxPoint >& aPoints ) const;
+    virtual void GetConnectionPoints( std::vector< wxPoint >& aPoints ) const;
 
     virtual bool CanIncrementLabel() const { return true; }
 
@@ -196,7 +196,7 @@
 
     virtual BITMAP_DEF GetMenuImage() const { return  add_text_xpm; }
 
-    virtual void GetNetListItem( vector<NETLIST_OBJECT*>& aNetListItems,
+    virtual void GetNetListItem( std::vector<NETLIST_OBJECT*>& aNetListItems,
                                  SCH_SHEET_PATH*          aSheetPath );
 
     virtual wxPoint GetPosition() const { return m_Pos; }
