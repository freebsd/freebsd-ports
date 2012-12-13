--- svn/WcEntry.h.orig	2008-11-09 01:23:48.000000000 +0900
+++ svn/WcEntry.h	2012-10-02 17:12:50.000000000 +0900
@@ -38,7 +38,7 @@
   WcEntry();
   
 public:
-  WcEntry( svn_wc_entry_t* );
+  WcEntry( const svn_wc_entry_t* );
   WcEntry( const WcEntry& src );
 
   Revnumber getRevnumber() const;
