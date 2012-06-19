--- build/myocamlbuild_prefix.ml.orig	2012-06-12 12:21:51.000000000 -0500
+++ build/myocamlbuild_prefix.ml	2012-06-12 12:25:27.000000000 -0500
@@ -325,7 +325,13 @@
            let sedexpr =
              Printf.sprintf "s/^\\?HAS_(%s)://; /HAS_.*:/d" tags
            in
-           Cmd(S[sed; A"-r"; A sedexpr; P(env "%.mllibp"); Sh">"; P(env "%.mllib")]));
+           (* FreeBSD 8.x and above have added -r that does exactly same as -E
+              for increased compatibility with GNU sed. Since FreeBSD still
+              supports 7.x that does not has -r, so use -E instead. *)
+           if is_fbsd then
+             Cmd(S[sed; A"-E"; A sedexpr; P(env "%.mllibp"); Sh">"; P(env "%.mllib")])
+           else
+             Cmd(S[sed; A"-r"; A sedexpr; P(env "%.mllibp"); Sh">"; P(env "%.mllib")]));
 
       (* Windows specific : redefinition of an existing rule in Ocaml_specific.ml,
          Louis please have a look to avoid the two copies at the end
