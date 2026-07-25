--- m4/sox.m4.orig	2021-05-09 20:19:07 UTC
+++ m4/sox.m4
@@ -109,7 +109,7 @@ AC_DEFUN([SOX_ARG], [SOX_NAME_TAG([$2], [
     m4_pushdef([opts_help], m4_bpatsubst(m4_apply([m4_join], [[/], opts]),
         \<optdef\>, m4_toupper(optdef)))
     m4_pushdef([opts_sh], m4_apply([m4_join], [[|], opts]))
-    m4_indir(AC_ARG_[]ATU, [N], AS_HELP_STRING([--ATL-N], [$3 (opts_help)]))
+    m4_indir(AC_ARG_[]ATU, N, AS_HELP_STRING([--ATL-N], [$3 (opts_help)]))
     HAVE_[]T=${ATL[]_[]L:-optdef}
     AS_CASE([$HAVE_[]T],
         [no],       [],
