--- src/core/uae/machdep/m68k.h.orig	2005-08-26 21:05:37 UTC
+++ src/core/uae/machdep/m68k.h
@@ -36,7 +36,7 @@ static __inline__ int cctrue(const int cc)
      case 14:return !ZFLG && (NFLG == VFLG); /* GT */
      case 15:return ZFLG || (NFLG != VFLG);  /* LE */
     }
-//    abort();
+//    uae_abort();
     return 0;
 }
 
