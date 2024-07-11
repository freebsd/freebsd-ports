--- setup/iso_codes.py.orig	2024-06-28 03:34:16 UTC
+++ setup/iso_codes.py
@@ -2,6 +2,7 @@ import fnmatch
 # License: GPLv3 Copyright: 2023, Kovid Goyal <kovid at kovidgoyal.net>
 
 import fnmatch
+import glob
 import optparse
 import os
 import shutil
@@ -20,22 +21,29 @@ class ISOData(Command):
     def add_options(self, parser):
         with suppress(optparse.OptionConflictError):  # ignore if option already added
             parser.add_option('--path-to-isocodes', help='Path to previously downloaded iso-codes-main.zip')
+            parser.add_option('--isocodes-extracted', default=False, action='store_true',
+                    help='Isocodes is a directory')
 
     def run(self, opts):
-        if self._zip_data is None:
-            if opts.path_to_isocodes:
-                with open(opts.path_to_isocodes, 'rb') as f:
-                    self._zip_data = BytesIO(f.read())
-                # get top level directory
-                top = {item.split('/')[0] for item in zipfile.ZipFile(self.zip_data).namelist()}
-                assert len(top) == 1
-                self.top_level = top.pop()
-            else:
-                self._zip_data = BytesIO(download_securely(self.URL))
+        if (opts.isocodes_extracted):
+            self.top_level = opts.path_to_isocodes
+            self.extracted = True
+        else:
+            if self._zip_data is None:
+                if opts.path_to_isocodes:
+                    with open(opts.path_to_isocodes, 'rb') as f:
+                        self._zip_data = BytesIO(f.read())
+                    # get top level directory
+                    top = {item.split('/')[0] for item in zipfile.ZipFile(self.zip_data).namelist()}
+                    assert len(top) == 1
+                    self.top_level = top.pop()
+                else:
+                    self._zip_data = BytesIO(download_securely(self.URL))
 
     def __init__(self):
         super().__init__()
         self._zip_data = None
+        self.extracted = False
         self.top_level = 'iso-codes-main'
 
     @property
@@ -43,23 +51,35 @@ class ISOData(Command):
         return self._zip_data
 
     def db_data(self, name: str) -> bytes:
-        with zipfile.ZipFile(self.zip_data) as zf:
-            with zf.open(f'{self.top_level}/data/{name}') as f:
+        if self.extracted:
+            src = f'{self.top_level}/data/{name}'
+            if not os.path.exists(src):
+                raise Exception(src + ' does not exist')
+            with open(src, 'rb') as f:
                 return f.read()
+        else:
+            with zipfile.ZipFile(self.zip_data) as zf:
+                with zf.open(f'{self.top_level}/data/{name}') as f:
+                    return f.read()
 
     def extract_po_files(self, name: str, output_dir: str) -> None:
         name = name.split('.', 1)[0]
         pat = f'{self.top_level}/{name}/*.po'
-        if self.zip_data is None:
-            self._zip_data = BytesIO(download_securely(self.URL))
-        with zipfile.ZipFile(self.zip_data) as zf:
-            for name in fnmatch.filter(zf.namelist(), pat):
+        if self.extracted:
+            for name in glob.glob(pat):
                 dest = os.path.join(output_dir, name.split('/')[-1])
-                zi = zf.getinfo(name)
-                with zf.open(zi) as src, open(dest, 'wb') as d:
-                    shutil.copyfileobj(src, d)
-                date_time = time.mktime(zi.date_time + (0, 0, -1))
-                os.utime(dest, (date_time, date_time))
+                shutil.copy2(name, dest)
+        else:
+            if self.zip_data is None:
+                self._zip_data = BytesIO(download_securely(self.URL))
+            with zipfile.ZipFile(self.zip_data) as zf:
+                for name in fnmatch.filter(zf.namelist(), pat):
+                    dest = os.path.join(output_dir, name.split('/')[-1])
+                    zi = zf.getinfo(name)
+                    with zf.open(zi) as src, open(dest, 'wb') as d:
+                        shutil.copyfileobj(src, d)
+                    date_time = time.mktime(zi.date_time + (0, 0, -1))
+                    os.utime(dest, (date_time, date_time))
 
 
 iso_data = ISOData()
