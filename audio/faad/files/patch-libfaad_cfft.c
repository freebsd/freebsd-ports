--- libfaad/cfft.c.orig	2007-11-01 12:33:29 UTC
+++ libfaad/cfft.c
@@ -60,8 +60,8 @@ static void passf4neg(const uint16_t ido
 static void passf5(const uint16_t ido, const uint16_t l1, const complex_t *cc, complex_t *ch,
                    const complex_t *wa1, const complex_t *wa2, const complex_t *wa3,
                    const complex_t *wa4, const int8_t isign);
-INLINE void cfftf1(uint16_t n, complex_t *c, complex_t *ch,
-                   const uint16_t *ifac, const complex_t *wa, const int8_t isign);
+/*INLINE void cfftf1(uint16_t n, complex_t *c, complex_t *ch,
+                   const uint16_t *ifac, const complex_t *wa, const int8_t isign);*/
 static void cffti1(uint16_t n, complex_t *wa, uint16_t *ifac);
 
 
