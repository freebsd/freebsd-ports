--- config/os/generic/time.h.orig	Fri May 26 04:45:16 2006
+++ config/os/generic/time.h	Wed Dec  6 08:22:45 2006
@@ -24,7 +24,9 @@
 
 #include <jack/internal.h>
 
-inline jack_time_t
+jack_time_t jack_get_microseconds_from_system (void);
+
+static inline jack_time_t
 jack_get_microseconds (void) {
 	return jack_get_microseconds_from_system ();
 }
