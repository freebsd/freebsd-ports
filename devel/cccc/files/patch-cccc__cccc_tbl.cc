--- ./cccc/cccc_tbl.cc.orig	2011-07-01 03:42:55.000000000 +0200
+++ ./cccc/cccc_tbl.cc	2011-07-01 03:43:07.000000000 +0200
@@ -96,7 +96,7 @@
   typename map_t::iterator value_iterator=map_t::find(old_item_ptr->key());
   if(value_iterator!=map_t::end())
     {
-      erase(value_iterator);
+      map_t::erase(value_iterator);
       retval=true;
     }
   return retval;
