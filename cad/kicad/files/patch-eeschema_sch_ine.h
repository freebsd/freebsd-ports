--- eeschema/sch_line.h.orig	2013-03-09 21:07:56.000000000 +0100
+++ eeschema/sch_line.h	2014-05-01 18:29:35.000000000 +0200
@@ -113,9 +113,9 @@
      */
     bool MergeOverlap( SCH_LINE* aLine );
 
-    void GetEndPoints( vector <DANGLING_END_ITEM>& aItemList );
+    void GetEndPoints( std::vector <DANGLING_END_ITEM>& aItemList );
 
-    bool IsDanglingStateChanged( vector< DANGLING_END_ITEM >& aItemList );
+    bool IsDanglingStateChanged( std::vector< DANGLING_END_ITEM >& aItemList );
 
     bool IsDangling() const { return m_startIsDangling || m_endIsDangling; }
 
@@ -123,13 +123,13 @@
 
     bool IsConnectable() const;
 
-    void GetConnectionPoints( vector< wxPoint >& aPoints ) const;
+    void GetConnectionPoints( std::vector< wxPoint >& aPoints ) const;
 
     wxString GetSelectMenuText() const;
 
     BITMAP_DEF GetMenuImage() const;
 
-    void GetNetListItem( vector<NETLIST_OBJECT*>& aNetListItems, SCH_SHEET_PATH* aSheetPath );
+    void GetNetListItem( std::vector<NETLIST_OBJECT*>& aNetListItems, SCH_SHEET_PATH* aSheetPath );
 
     bool operator <( const SCH_ITEM& aItem ) const;
 
