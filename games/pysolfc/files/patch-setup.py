* Avoid staging issues by skipping directories that only contain
  subdirectories.

* Skip locale files if NLS is disabled (otherwise enable it via
  post-patch target).

--- setup.py.orig	2024-03-31 16:23:14 UTC
+++ setup.py
@@ -14,6 +14,8 @@ def get_data_files(source, destination):
     destination using the data_files keyword of setuptools.setup."""
     for path, _, files in os.walk(source):
         files = [os.path.join(path, f) for f in files]
+        if (len(files) == 0):
+            continue
         path = path.replace(source, destination, 1)
         yield (path, files)
 
@@ -44,7 +46,7 @@ for d in ddirs:
     data_files += get_data_files(os.path.join('data', d),
                                  os.path.join(data_dir, d))
 
-data_files += get_data_files('locale', locale_dir)
+#%%NLS%%data_files += get_data_files('locale', locale_dir)
 
 if os.name == 'posix':
     for size in os.listdir('data/images/icons'):
