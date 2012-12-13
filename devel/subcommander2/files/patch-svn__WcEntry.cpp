--- svn/WcEntry.cpp.orig	2008-11-09 01:23:48.000000000 +0900
+++ svn/WcEntry.cpp	2012-10-02 17:12:20.000000000 +0900
@@ -20,7 +20,7 @@
 {
 }
   
-WcEntry::WcEntry( svn_wc_entry_t* entry )
+WcEntry::WcEntry( const svn_wc_entry_t* entry )
 {
   _name        = sc::String(entry->name);
   _revision    = entry->revision;
