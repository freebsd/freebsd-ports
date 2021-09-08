--- build-aux/cargo.sh.orig	2021-09-08 13:22:45 UTC
+++ build-aux/cargo.sh
@@ -17,10 +17,10 @@ then
     echo "** DEBUG MODE **"
     cargo build --manifest-path \
         "$MESON_SOURCE_ROOT"/Cargo.toml && \
-        cp "$CARGO_TARGET_DIR"/debug/shortwave $APP_OUTPUT
+        cp "$CARGO_TARGET_DIR"/$CARGO_BUILD_TARGET/debug/shortwave $APP_OUTPUT
 else
     echo "** RELEASE MODE **"
     cargo build --manifest-path \
         "$MESON_SOURCE_ROOT"/Cargo.toml --release && \
-        cp "$CARGO_TARGET_DIR"/release/shortwave $APP_OUTPUT
+        cp "$CARGO_TARGET_DIR"/$CARGO_BUILD_TARGET/release/shortwave $APP_OUTPUT
 fi
