--- scripts/cargo.sh.orig	2021-12-04 18:15:44 UTC
+++ scripts/cargo.sh
@@ -24,4 +24,4 @@ if test -d vendor; then
 fi
 
 cargo build ${ARGS[@]} --manifest-path="$MESON_SOURCE_ROOT"/Cargo.toml -p podcasts-gtk
-cp "$CARGO_TARGET_DIR"/${TARGET}/podcasts-gtk "$OUTPUT"
+cp "$CARGO_TARGET_DIR"/${CARGO_BUILD_TARGET}/${TARGET}/podcasts-gtk "$OUTPUT"
