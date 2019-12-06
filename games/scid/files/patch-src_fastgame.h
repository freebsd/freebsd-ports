--- src/fastgame.h.orig	2019-11-21 14:15:35 UTC
+++ src/fastgame.h
@@ -433,7 +433,7 @@ class FastGame { (private)
 
 	static inline squareT decodeKing (squareT from, byte val) {
 		ASSERT (val <= 8);
-		static const char sqdiff[] = { 0, -9, -8, -7, -1, 1, 7, 8, 9};
+		static const signed char sqdiff[] = { 0, -9, -8, -7, -1, 1, 7, 8, 9};
 		return 0x3F & (from + sqdiff[val]);
 	}
 	static inline squareT decodeQueen2byte (byte val) {
@@ -447,7 +447,7 @@ class FastGame { (private)
 	}
 	static inline squareT decodeKnight (squareT from, byte val) {
 		ASSERT (val <= 16);
-		static const char sqdiff[] = { 0, -17, -15, -10, -6, 6, 10, 15, 17, 0, 0, 0, 0, 0, 0, 0 };
+		static const signed char sqdiff[] = { 0, -17, -15, -10, -6, 6, 10, 15, 17, 0, 0, 0, 0, 0, 0, 0 };
 		return 0x3F & (from + sqdiff[val]);
 	}
 	static inline squareT decodeRook (squareT from, byte val) {
