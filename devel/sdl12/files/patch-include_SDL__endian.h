
$FreeBSD$

--- include/SDL_endian.h.orig
+++ include/SDL_endian.h
@@ -68,7 +68,7 @@
 #elif defined(__GNUC__) && defined(__x86_64__)
 static __inline__ Uint16 SDL_Swap16(Uint16 x)
 {
-	__asm__("xchgb %b0,%h0" : "=q" (x) :  "0" (x));
+	__asm__("xchgb %b0,%h0" : "=Q" (x) :  "0" (x));
 	return x;
 }
 #elif defined(__GNUC__) && (defined(__powerpc__) || defined(__ppc__))
