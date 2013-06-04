--- lib/xparam/xp_hvl.h.orig
+++ lib/xparam/xp_hvl.h
@@ -51,9 +51,9 @@
 			// t_ptr may be 0
 			void append_copy(const T* t_ptr) {
 				if (t_ptr)
-					push_back( Handle<T>(get_copy_of(*t_ptr)) );
+					this->push_back( Handle<T>(get_copy_of(*t_ptr)) );
 				else
-					push_back( Handle<T>() );
+					this->push_back( Handle<T>() );
 			}
 
 			// t_ptr may be 0
