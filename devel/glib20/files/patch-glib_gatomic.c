--- glib/gatomic.c.orig	Thu Jul  6 11:21:02 2006
+++ glib/gatomic.c	Thu Jul  6 11:18:48 2006
@@ -414,14 +414,14 @@
 g_atomic_int_exchange_and_add (volatile gint *atomic,
 			       gint           val)
 {
-  return __sync_fetch_and_add (atomic, val);
+  return __sync_fetch_and_add_si (atomic, val);
 }
  
 void
 g_atomic_int_add (volatile gint *atomic, 
 		  gint val)
 {
-  __sync_fetch_and_add (atomic, val);
+  __sync_fetch_and_add_si (atomic, val);
 }
 
 gboolean
@@ -429,7 +429,7 @@
 				   gint           oldval, 
 				   gint           newval)
 {
-  return __sync_bool_compare_and_swap (atomic, oldval, newval);
+  return __sync_bool_compare_and_swap_si (atomic, oldval, newval);
 }
 
 gboolean
@@ -437,7 +437,7 @@
 				       gpointer           oldval, 
 				       gpointer           newval)
 {
-  return __sync_bool_compare_and_swap ((long *)atomic, 
+  return __sync_bool_compare_and_swap_di ((long *)atomic, 
 				       (long)oldval, (long)newval);
 }
 
