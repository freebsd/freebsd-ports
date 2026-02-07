Depend on PYTHON_BINARY as well if OFFLINE_BUILD is used to let us specify the
current Python interpreter that is used in the system.

Otherwise the build emits following error message during the creation of
the Python wheels:

[...]
FAILED: /wrkdirs/usr/ports/games/anki/work/anki-25.07.2/out/wheels/aqt-25.7.2-py3-none-any.whl
/wrkdirs/usr/ports/games/anki/work/anki-25.07.2/out/rust/release/runner run --env="UV_PROJECT_ENVIRONMENT=/wrkdirs/usr/ports/games/anki/work/anki-25.07.2/out/pyenv" --env="A
NKI_WHEEL_TAG=py3-none-any" /usr/local/bin/uv build --wheel --out-dir=/wrkdirs/usr/ports/games/anki/work/anki-25.07.2/out/wheels/ --project=qt
  × Failed to build `/wrkdirs/usr/ports/games/anki/work/anki-25.07.2/qt`
    ╰─▶ No interpreter found for Python 3.13.5 in virtual environments, managed
          installations, or search path
          Failed with code Some(2): /usr/local/bin/uv build --wheel --out-dir=/wrkdirs/usr/ports/games/anki/work/anki-25.07.2/out/wheels/ --project=qt
[...]

The environment variables UV_NO_BUILD_ISOLATION=1 and UV_OFFLINE=1 are also
required to run "uv" in offline mode and to make use of the Python packages
outside of the pseudo-venv.

--- build/configure/src/python.rs.orig	2025-07-07 16:49:54 UTC
+++ build/configure/src/python.rs
@@ -119,11 +119,19 @@ impl BuildAction for BuildWheel {
 
 impl BuildAction for BuildWheel {
     fn command(&self) -> &str {
-        "$uv build --wheel --out-dir=$out_dir --project=$project_dir"
+        if std::env::var("OFFLINE_BUILD").is_ok() && std::env::var("PYTHON_BINARY").is_ok() {
+            "$uv build --python=$python_binary --wheel --out-dir=$out_dir --project=$project_dir"
+        } else {
+            "$uv build --wheel --out-dir=$out_dir --project=$project_dir"
+        }
     }
 
     fn files(&mut self, build: &mut impl FilesHandle) {
         if std::env::var("OFFLINE_BUILD").ok().as_deref() == Some("1") {
+            let python_binary =
+                std::env::var("PYTHON_BINARY").expect("PYTHON_BINARY must be set in OFFLINE_BUILD mode");
+            build.add_variable("python_binary", python_binary);
+
             let uv_path =
                 std::env::var("UV_BINARY").expect("UV_BINARY must be set in OFFLINE_BUILD mode");
             build.add_inputs("uv", inputs![uv_path]);
