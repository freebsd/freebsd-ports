--- scripts/cargo.sh.orig	2021-09-08 13:34:20 UTC
+++ scripts/cargo.sh
@@ -22,4 +22,4 @@ if test -d vendor; then
 fi
 
 cargo build ${ARGS[@]} --manifest-path="$1"/Cargo.toml -p podcasts-gtk
-cp "$CARGO_TARGET_DIR"/${TARGET}/podcasts-gtk "$OUTPUT"
+cp "$CARGO_TARGET_DIR"/${CARGO_BUILD_TARGET}/${TARGET}/podcasts-gtk "$OUTPUT"
