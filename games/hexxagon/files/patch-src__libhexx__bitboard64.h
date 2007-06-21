--- ./src/libhexx/bitboard64.h.orig	Fri Jan 14 00:19:07 2005
+++ ./src/libhexx/bitboard64.h	Sun Jun  3 18:27:59 2007
@@ -26,8 +26,12 @@
 #include <netinet/in.h>
 #include <iostream>
 
-namespace libhexx 
+namespace libhexx
 {
+	
+	std::ostream& operator<<(std::ostream &output, const class BitBoard64 &b);
+	std::istream& operator>>(std::istream &input, class BitBoard64 &b);
+	
 	class BitBoard64
 	{
 	public:
