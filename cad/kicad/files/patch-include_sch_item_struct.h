--- include/sch_item_struct.h.orig	2013-03-09 21:07:56.000000000 +0100
+++ include/sch_item_struct.h	2014-05-01 17:32:49.000000000 +0200
@@ -47,7 +47,7 @@
 
 typedef boost::ptr_vector< SCH_ITEM > SCH_ITEMS;
 typedef SCH_ITEMS::iterator SCH_ITEMS_ITR;
-typedef vector< SCH_ITEMS_ITR > SCH_ITEMS_ITRS;
+typedef std::vector< SCH_ITEMS_ITR > SCH_ITEMS_ITRS;
 
 
 #define FMT_IU          SCH_ITEM::FormatInternalUnits
@@ -228,7 +228,7 @@
      *
      * @param aItemList - List of DANGLING_END_ITEMS to add to.
      */
-    virtual void GetEndPoints( vector< DANGLING_END_ITEM >& aItemList ) {}
+    virtual void GetEndPoints( std::vector< DANGLING_END_ITEM >& aItemList ) {}
 
     /**
      * Function IsDanglingStateChanged
@@ -243,7 +243,7 @@
      * @param aItemList - List of items to test item against.
      * @return True if the dangling state has changed from it's current setting.
      */
-    virtual bool IsDanglingStateChanged( vector< DANGLING_END_ITEM >& aItemList ) { return false; }
+    virtual bool IsDanglingStateChanged( std::vector< DANGLING_END_ITEM >& aItemList ) { return false; }
 
     virtual bool IsDangling() const { return false; }
 
@@ -273,7 +273,7 @@
      *
      * @param aPoints List of connection points to add to.
      */
-    virtual void GetConnectionPoints( vector< wxPoint >& aPoints ) const { }
+    virtual void GetConnectionPoints( std::vector< wxPoint >& aPoints ) const { }
 
     /**
      * Function ClearConnections
@@ -340,7 +340,7 @@
      * net list objects associated with them.
      * </p>
      */
-    virtual void GetNetListItem( vector<NETLIST_OBJECT*>& aNetListItems,
+    virtual void GetNetListItem( std::vector<NETLIST_OBJECT*>& aNetListItems,
                                  SCH_SHEET_PATH*          aSheetPath ) { }
 
     /**
