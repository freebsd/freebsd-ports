--- src/tools.cc.orig	2022-10-20 09:17:55 UTC
+++ src/tools.cc
@@ -1135,11 +1135,13 @@ uint64_t random64()
 /* ###### Get 32-bit random value ######################################## */
 uint32_t random32()
 {
+/*
 #ifdef NDEBUG
 #warning Using OMNeT++ random generator instead of time-seeded one!
    const double value = uniform(0.0, (double)0xffffffff);
    return((uint32_t)rint(value));
 #else
+*/
    uint32_t number;
 
    switch(RandomSource) {
@@ -1165,7 +1167,7 @@ uint32_t random32()
    const uint16_t a = random() & 0xffff;
    const uint16_t b = random() & 0xffff;
    return( (((uint32_t)a) << 16) | (uint32_t)b );
-#endif
+
 }
 
 
