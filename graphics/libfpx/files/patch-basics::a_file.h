--- basics/a_file.h	Sat Dec 23 17:10:00 2000
+++ basics/a_file.h	Thu Jan 18 11:41:58 2001
@@ -46,12 +46,10 @@
 //  Global Functions
 //  ________________
 
-#ifdef _WINDOWS
 uint16          shortswap(uint16);  // Swap for Big/Little Endian
 uint32          longswap(uint32);   // Swap for Big/Little Endian
 #  define int32swap   longswap
 #  define int16swap   shortswap
-#endif
 
 //  Classes Declarations
 //  --------------------
@@ -310,7 +308,6 @@
 
 #ifdef DEFINE_INT32_FUNCTIONS
 
-#ifdef _WINDOWS
 inline uint32   longswap( uint32 x )
 {
   uint32 a, b;
@@ -318,7 +315,6 @@
   b = x & 0x0000ffff;
   return ( ((uint32)shortswap((uint16)b) << 16) | (uint32)shortswap((uint16)a) );
 }
-#endif
 
 inline Boolean Fichier::Ecriture(int32 ceLong)
 {
@@ -376,7 +372,6 @@
 
 
 // Added by GDN
-#ifdef _WINDOWS
 inline uint16   shortswap( uint16 x )
 {
   uint16 a, b;
@@ -384,7 +379,6 @@
   b = x & 0x00ff;
   return ( (b << 8) | a );
 }
-#endif
 
 inline Boolean Fichier::Ecriture(short ceShort)
 {
@@ -487,9 +481,9 @@
 inline Boolean Fichier::EcritureTableau(short *array, int32 nshort)
 {
   Boolean ret;
-
+  int32 i;
 #ifndef __bigEndian
-  for (int32 i = 0; i < nshort; i++)
+  for (i = 0; i < nshort; i++)
     array[i] = shortswap (array[i]);
 #endif
 
@@ -509,8 +503,9 @@
 inline Boolean Fichier::EcritureTableau( int32 *array, int32 t)
 {
   Boolean ret;
+  int32 i;
 #ifndef __bigEndian
-  for (int32 i = 0; i < t; i++)
+  for (i = 0; i < t; i++)
     array[i] = int32swap (array[i]);
 #endif
 
