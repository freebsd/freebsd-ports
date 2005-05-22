Issutracker : #i49681#
CWS         : N/A
Author      : NAKATA Maho <maho@openoffice.org> (JCA)
Description : powerof2() is already defined

Index: canvas/inc/canvas/canvastools.hxx
===================================================================
RCS file: /cvs/gsl/canvas/inc/canvas/canvastools.hxx,v
retrieving revision 1.7
diff -u -r1.7 canvastools.hxx
--- canvas/inc/canvas/canvastools.hxx	30 Mar 2005 07:34:18 -0000	1.7
+++ canvas/inc/canvas/canvastools.hxx	6 Apr 2005 01:22:58 -0000
@@ -133,9 +133,9 @@
 		 */
 
 		// mickey's math tricks...
-		inline unsigned int powerof2( unsigned int c ) { return 0x1 << c; }
-		inline unsigned int mask( unsigned int c ) { return ((unsigned int)(-1)) / (powerof2(powerof2(c)) + 1); }
-		inline unsigned int count( unsigned int x, unsigned int c ) { return ((x) & mask(c)) + (((x) >> (powerof2(c))) & mask(c)); }
+		inline unsigned int powerof2_ooo( unsigned int c ) { return 0x1 << c; }
+		inline unsigned int mask( unsigned int c ) { return ((unsigned int)(-1)) / (powerof2_ooo(powerof2_ooo(c)) + 1); }
+		inline unsigned int count( unsigned int x, unsigned int c ) { return ((x) & mask(c)) + (((x) >> (powerof2_ooo(c))) & mask(c)); }
 		template<typename T>
 		inline unsigned int bitcount( T c ) {
 			unsigned int nByteIndex = 0;
