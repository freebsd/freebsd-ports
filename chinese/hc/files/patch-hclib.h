--- hclib.h.orig	2011-09-05 14:32:54.000000000 +0800
+++ hclib.h	2011-09-05 14:34:36.000000000 +0800
@@ -114,7 +114,7 @@ extern int hc_convert(/* int mode, u_int
    Hanzi that cannot be converted is replaced by a "box" character code. 
    If do_mult is true, all multiple mappings will be shown in <<...>>.
 */
-extern hc_convert_fp(/* FILE *ifp, FILE *ofp, int mode, int do_mult */);
+extern int hc_convert_fp(/* FILE *ifp, FILE *ofp, int mode, int do_mult */);
 
 /* Convert a hanzi code according to mode, and return the converted code.
    In case of multiple mappings, an arbitrary one is returned.
