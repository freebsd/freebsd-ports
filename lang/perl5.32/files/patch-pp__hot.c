--- pp_hot.c.orig	2021-01-08 21:20:36 UTC
+++ pp_hot.c
@@ -1413,7 +1413,7 @@ PP(pp_add)
         U32 flags = (svl->sv_flags & svr->sv_flags);
         if (flags & SVf_IOK) {
             /* both args are simple IVs */
-            UV topl, topr;
+            UVINT topl, topr;
             il = SvIVX(svl);
             ir = SvIVX(svr);
           do_iv:
