--- tools/build/myocamlbuild_prefix.ml.orig	2012-08-07 20:41:25.000000000 -0500
+++ tools/build/myocamlbuild_prefix.ml	2012-08-07 20:41:44.000000000 -0500
@@ -342,7 +342,7 @@
               for increased compatibility with GNU sed. Since FreeBSD still
               supports 7.x that does not has -r, so use -E instead. The -r
               does not exist in MacOS X sed either. *)
-           if is_fbsd && is_mac then
+           if is_fbsd || is_mac then
              Cmd(S[sed; A"-E"; A sedexpr; P(env "%.mllibp"); Sh">"; P(env "%.mllib")])
            else
              Cmd(S[sed; A"-r"; A sedexpr; P(env "%.mllibp"); Sh">"; P(env "%.mllib")]));
