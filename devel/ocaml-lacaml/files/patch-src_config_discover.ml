--- src/config/discover.ml.orig	2023-05-16 14:23:01 UTC
+++ src/config/discover.ml
@@ -46,8 +46,6 @@ let () =
       (* -march=native is not supported on Apple ARM64 yet.
          Its support was introduced in clang >= 15.0.0 *)
       match maybe_system, maybe_arch with
-      | Some "macosx", Some "arm64"
-      | _, (None | Some ("ppc64" | "ppc64le" | "unknown")) -> shared
-      | _ -> "-march=native" :: shared
+      | _ -> shared
     in
     C.Flags.write_sexp "extra_c_flags.sexp" extra_cflags)
