--- Seat.h.orig	Tue Aug 19 12:12:00 2003
+++ Seat.h	Tue Aug 19 12:12:40 2003
@@ -148,7 +148,7 @@
 };
 
 // Class Seat 
-inline Seat::Available() const
+inline int Seat::Available() const
 {
 	return _isAvailable;
 }
