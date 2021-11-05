--- vendor/cc-1.0.69/src/lib.rs.orig	2021-10-18 11:05:53 UTC
+++ vendor/cc-1.0.69/src/lib.rs
@@ -1700,6 +1700,9 @@ impl Build {
                         if target.contains("linux") && arch.starts_with("64") {
                             cmd.args.push(("-march=rv64gc").into());
                             cmd.args.push("-mabi=lp64d".into());
+                        } else if target.contains("freebsd") && arch.starts_with("64") {
+                            cmd.args.push(("-march=rv64gc").into());
+                            cmd.args.push("-mabi=lp64d".into());
                         } else if target.contains("linux") && arch.starts_with("32") {
                             cmd.args.push(("-march=rv32gc").into());
                             cmd.args.push("-mabi=ilp32d".into());
