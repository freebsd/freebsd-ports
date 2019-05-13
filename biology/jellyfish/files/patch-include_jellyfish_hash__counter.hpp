--- include/jellyfish/hash_counter.hpp.orig	2018-04-16 12:46:09 UTC
+++ include/jellyfish/hash_counter.hpp
@@ -213,7 +213,7 @@ class hash_counter { (protected)
           new_ary_ = new  array(ary_->size(), ary_->key_len(), ary_->val_len() + 1,
                                 ary_->max_reprobe(), ary_->reprobes());
         }
-      } catch(typename array::ErrorAllocation e) {
+      } catch(typename array::ErrorAllocation &e) {
         new_ary_ = 0;
       }
     }
