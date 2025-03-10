--- src/config/discover.ml.orig	2024-12-26 19:34:31 UTC
+++ src/config/discover.ml
@@ -46,7 +46,7 @@ let () =
       (* -march=native is not supported on Apple ARM64 yet.
          Its support was introduced in clang >= 15.0.0 *)
       match maybe_system, maybe_arch with
-      | Some "macosx", Some "arm64"
+      | Some "bsd_elf", _
       | _, (None | Some ("ppc64" | "ppc64le" | "unknown")) -> shared
       | _ -> "-march=native" :: shared
     in
