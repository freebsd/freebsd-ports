-- Ensure the parent directory exists before copying the reference bindings file,
-- so the build does not fail when data/bindings has not been created yet.
--- setupsrc/base.py.orig	2026-09-24 11:06:16 UTC
+++ setupsrc/base.py
@@ -644,6 +644,7 @@ def _apply_refbindings(target_path, version):
     record_ver = PdfiumVer.pinned
     if version != record_ver:
         log(f"Warning: binary/bindings version mismatch ({version} != {record_ver}). This is ABI-unsafe!")
+    mkdir(target_path.parent)
     shutil.copyfile(RefBindingsFile, target_path)
 
 # TODO make version mandatory
