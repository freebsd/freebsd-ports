--- ./Seat.h.orig	2013-10-29 15:12:13.000000000 -0200
+++ ./Seat.h	2013-10-29 15:12:13.000000000 -0200
@@ -148,7 +148,7 @@
 };
 
 // Class Seat 
-inline Seat::Available() const
+inline int Seat::Available() const
 {
 	return _isAvailable;
 }
