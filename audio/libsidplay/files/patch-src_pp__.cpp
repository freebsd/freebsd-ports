--- src/pp_.cpp.orig	2001-12-28 23:10:17 UTC
+++ src/pp_.cpp
@@ -40,6 +40,8 @@ static udword outputLen;
 static bool isCompressed;
 static bool globalError;
 
+using namespace std;
+
 
 // Move four bytes to Motorola big-endian double-word.
 static inline void bytesTOudword()
