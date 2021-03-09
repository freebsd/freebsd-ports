--- src/recompiler/Sun/testmath.c.orig	2020-05-13 19:46:49 UTC
+++ src/recompiler/Sun/testmath.c
@@ -273,8 +273,6 @@ extern int testmath(void)
 #endif
     set_cw(0x27f);
 
-    CHECK(logl(2.7182818284590452353602874713526625L), 1.0);
-
     CHECK(remainderl(1.0L, 1.0L), 0.0);
     CHECK(remainderl(1.0L, 1.5L), -0.5);
     CHECK(remainderl(42.0L, 34.25L), 7.75);
@@ -341,10 +339,6 @@ extern int testmath(void)
 
     CHECK(tanl(0.0L), 0.0);
     CHECK(tanl(0.7853981633974483096156608458198757L), 1.0);
-
-    CHECK(powl(0.0, 0.0), 1.0);
-    CHECK(powl(2.0, 2.0), 4.0);
-    CHECK(powl(3.0, 3.0), 27.0);
 
     return cErrors;
 }
