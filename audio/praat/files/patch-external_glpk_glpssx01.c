--- external/glpk/glpssx01.c.orig	2026-06-09 15:27:29 UTC
+++ external/glpk/glpssx01.c
@@ -787,7 +787,7 @@ void ssx_change_basis(SSX *ssx)
          /* update factorization of the basis matrix */
          if (bfx_update(ssx->binv, p))
          {  if (ssx_factorize(ssx))
-               xassert(("Internal error: basis matrix is singular", 0));
+               xassert(0 && ("Internal error: basis matrix is singular"));
          }
       }
       return;
