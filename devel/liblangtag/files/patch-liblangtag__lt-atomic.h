--- liblangtag/lt-atomic.h	2012-11-06 09:15:59.000000000 -0600
+++ liblangtag/lt-atomic.h	2012-11-06 09:24:15.000000000 -0600
@@ -93,7 +93,7 @@
 {
 	lt_bool_t retval;
 
-	lt_return_if_fail (v != NULL, FALSE);
+	lt_return_val_if_fail (v != NULL, FALSE);
 
 	pthread_mutex_lock(&__lt_atomic_lock);
 	retval = --(*v) == 0;
