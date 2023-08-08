--- cargo-crates/pgx-pg-sys-0.6.1/build.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/pgx-pg-sys-0.6.1/build.rs
@@ -566,6 +566,7 @@ fn run_bindgen(pg_config: &PgConfig, include_h: &PathB
     let bindings = bindgen::Builder::default()
         .header(include_h.display().to_string())
         .clang_arg(&format!("-I{}", includedir_server.display()))
+        .clang_arg("-I/usr/local/include")
         .clang_args(&extra_bindgen_clang_args(pg_config)?)
         .parse_callbacks(Box::new(PgxOverrides::default()))
         .blocklist_type("(Nullable)?Datum") // manually wrapping datum types for correctness
