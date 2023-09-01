--- website/scripts/test_images.py.orig	2023-08-28 17:56:26 UTC
+++ website/scripts/test_images.py
@@ -127,8 +127,8 @@ def write_exr_page(rst_lpath, exr_url, exr_filename, e
         
         # Download the exr via wget
         
-        print(f'wget {exr_url}')
-        result = run (['wget', exr_url, '-O', local_exr], 
+        print(f'cp {exr_lpath}')
+        result = run (['/bin/cp', '-f', f'{os.environ["FREEBSD_DIST"]}/{exr_lpath}', local_exr], 
                       stdout=PIPE, stderr=PIPE, universal_newlines=True)
         if result.returncode != 0 or not os.path.isfile(local_exr):
             raise Exception(f'failed to read {exr_url}: no such file {local_exr}')
@@ -141,7 +141,7 @@ def write_exr_page(rst_lpath, exr_url, exr_filename, e
                           stdout=PIPE, stderr=PIPE, universal_newlines=True)
         
             if result.returncode != 0 or not os.path.isfile(jpg_lpath):
-                raise Exception(f'error: failed to convert {exr_url} to {jpg_lpath}: returncode={result.returncode}, stderr={result.stderr}')
+                raise Exception(f'error: failed to convert {exr_url} ({local_exr}) to {jpg_lpath}: returncode={result.returncode}, stderr={result.stderr}')
         
         # Read the header
         
@@ -227,7 +227,7 @@ def write_readme(index_file, repo, tag, lpath):
         # Download via wget
         
         readme_url = f'{repo}/{tag}/{lpath}' 
-        result = run (['wget', readme_url, '-O', local_readme], 
+        result = run (['/bin/cp', '-f', f'{os.environ["FREEBSD_DIST"]}/{lpath}', local_readme], 
                       stdout=PIPE, stderr=PIPE, universal_newlines=True)
         if result.returncode != 0:
             raise FileNotFoundError(result.stderr)
