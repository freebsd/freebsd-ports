--- eeschema/sch_bus_entry.h.orig	2013-03-09 21:07:56.000000000 +0100
+++ eeschema/sch_bus_entry.h	2014-05-01 18:21:38.000000000 +0200
@@ -114,7 +114,7 @@
 
     bool IsConnectable() const { return true; }
 
-    void GetConnectionPoints( vector< wxPoint >& aPoints ) const;
+    void GetConnectionPoints( std::vector< wxPoint >& aPoints ) const;
 
     wxString GetSelectMenuText() const;
 
