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
@@ -549,9 +555,14 @@
         flag ["ocaml"; "native"; "link"; tag] (S[A"-ccopt";A("-L"^dir);A"-cclib";A("-l"^name)]);
       in
 
-      (* In the memory.c in FreeBSD part that uses kvm_getprocs() required link with -lkvm. *)
       if is_fbsd then
-        flag ["use_stubs"; "link"] (S[A "-cclib";A "-lkvm"]);
+        (* In the memory.c in FreeBSD part that uses kvm_getprocs() required
+           link with -lkvm. The stubs needs to be compiled with -liconv too. *)
+        flag ["use_stubs"; "link"] (S[A "-cclib";A "-lkvm";A"-ccopt";A "-L/usr/local/lib";A "-cclib";A "-liconv"]);
+        (* Build with converters/libiconv port, which it installs in the
+           /usr/local by default *)
+        flag ["iconv"; "compile"] (S[A"-I";A "/usr/local/include"]);
+        flag ["iconv"; "link"] (S[A"-ccopt";A "-L/usr/local/lib";A "-cclib";A "-liconv"]);
 
 (* -- Don't forget that the rest of the "mlstate build stdlib" is in --
    -- myocamlbuild_suffix.ml. The rest comes from the build_rules*.ml in each repo -- *)
