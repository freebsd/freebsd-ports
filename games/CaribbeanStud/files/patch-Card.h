--- Card.h.orig	Tue Aug 19 11:57:32 2003
+++ Card.h	Tue Aug 19 11:58:21 2003
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
