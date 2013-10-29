--- ./Card.h.orig	2013-10-29 15:12:13.000000000 -0200
+++ ./Card.h	2013-10-29 15:12:13.000000000 -0200
@@ -59,7 +59,7 @@
 
 // Class Card 
 
-inline Card::operator==(const Card &right) const
+inline int Card::operator==(const Card &right) const
 {
 	return ( _suit == right._suit &&
 				(_rank == right._rank ||
@@ -69,7 +69,7 @@
 		    );
 }
 
-inline Card::operator!=(const Card &right) const
+inline int Card::operator!=(const Card &right) const
 {
 	return !( operator == (right) );
 }
