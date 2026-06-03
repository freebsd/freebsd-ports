--- setupsrc/base.py.orig	2026-04-05 20:07:20 UTC
+++ setupsrc/base.py
@@ -681,6 +681,7 @@ def run_ctypesgen(
         record_ver = PdfiumVer.pinned
         if version != record_ver:
             log(f"Warning: binary/bindings version mismatch ({version} != {record_ver}). This is ABI-unsafe!")
+        mkdir(target_path.parent)
         shutil.copyfile(RefBindingsFile, target_path)
         return target_path
     
@@ -767,20 +768,21 @@ def build_pdfium_bindings(version, headers_dir=None, *
         else:
             log(f"Bindings cache state differs:", prev_info, curr_info, sep="\n")
     
-    # try to reuse headers if only bindings params differ, not version
-    if prev_ver == version and headers_dir.exists() and list(headers_dir.glob("fpdf*.h")):
-        log("Using cached headers")
-    else:
-        log("Downloading headers...")
-        mkdir(headers_dir)
-        archive_url = f"{PdfiumURL}/+archive/refs/heads/chromium/{version}/public.tar.gz"
-        archive_path = DataDir_Bindings / "pdfium_public.tar.gz"
-        url_request.urlretrieve(archive_url, archive_path)
-        with tarfile.open(archive_path) as tar:
-            for m in tar.getmembers():
-                if m.isfile() and re.fullmatch(r"fpdf(\w+)\.h", m.name, flags=re.ASCII):
-                    tar_extract_file(tar, m, headers_dir/m.name)
-        archive_path.unlink()
+    if not USE_REFBINDINGS:
+        # try to reuse headers if only bindings params differ, not version
+        if prev_ver == version and headers_dir.exists() and list(headers_dir.glob("fpdf*.h")):
+            log("Using cached headers")
+        else:
+            log("Downloading headers...")
+            mkdir(headers_dir)
+            archive_url = f"{PdfiumURL}/+archive/refs/heads/chromium/{version}/public.tar.gz"
+            archive_path = DataDir_Bindings / "pdfium_public.tar.gz"
+            url_request.urlretrieve(archive_url, archive_path)
+            with tarfile.open(archive_path) as tar:
+                for m in tar.getmembers():
+                    if m.isfile() and re.fullmatch(r"fpdf(\w+)\.h", m.name, flags=re.ASCII):
+                        tar_extract_file(tar, m, headers_dir/m.name)
+            archive_path.unlink()
     
     log(f"Building bindings ...")
     bindings_path = DataDir_Bindings/BindingsFN
