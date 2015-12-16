--- cccc/cccc_tbl.cc.orig	2006-01-05 16:05:30 UTC
+++ cccc/cccc_tbl.cc
@@ -96,7 +96,7 @@ bool CCCC_Table<T>::remove(T* old_item_p
   typename map_t::iterator value_iterator=map_t::find(old_item_ptr->key());
   if(value_iterator!=map_t::end())
     {
-      erase(value_iterator);
+      map_t::erase(value_iterator);
       retval=true;
     }
   return retval;
