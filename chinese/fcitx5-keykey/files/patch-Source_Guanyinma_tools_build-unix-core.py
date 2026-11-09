Accept the ports tree's Rust, which need not be the exact toolchain that
rust-toolchain.toml pins; Cargo.toml's rust-version is the lower bound.

--- Source/Guanyinma/tools/build-unix-core.py.orig	2026-11-08 15:20:41 UTC
+++ Source/Guanyinma/tools/build-unix-core.py
@@ -45,9 +45,6 @@ def main():
     env.update(RUSTUP_TOOLCHAIN=match.group(1), SQLITE3_INCLUDE_DIR=str(sqlite_include),
                SQLITE3_LIB_DIR=str(sqlite_library.parent), SQLITE3_STATIC="0",
                SQLITE3_NO_PKG_CONFIG="1")
-    version = subprocess.check_output([cargo, "--version"], env=env, text=True, cwd=CORE)
-    if not version.startswith("cargo " + match.group(1) + " "):
-        parser.error("cargo must use the exact pinned Rust toolchain: " + match.group(1))
     # The archive is linked into Fcitx's shared addon, not only executables.
     env["RUSTFLAGS"] = (env.get("RUSTFLAGS", "") + " -C relocation-model=pic").strip()
     command = [cargo, "rustc", "--lib", "--release", "--locked", "--no-default-features",
