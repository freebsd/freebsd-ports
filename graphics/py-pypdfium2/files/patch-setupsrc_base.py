-- Ensure the parent directory exists before copying the reference bindings file,
-- so the build does not fail when the target directory has not been created yet.
--- setupsrc/base.py.orig	2026-11-10 12:42:34 UTC
+++ setupsrc/base.py
@@ -642,7 +642,7 @@ def _apply_refbindings(target_path, version):
     record_ver = PdfiumVer.pinned
     if version != record_ver:
         log(f"Warning: binary/bindings version mismatch ({version} != {record_ver}). This is ABI-unsafe!")
-    # TODO check if we need mkdir(target_path.parent) here
+    mkdir(target_path.parent)
     shutil.copyfile(RefBindingsFile, target_path)
