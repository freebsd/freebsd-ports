--- singleheader/amalgamate.py.orig	2025-01-23 23:04:46 UTC
+++ singleheader/amalgamate.py
@@ -236,7 +236,7 @@ def get_timestamp():
             raise ValueError(f"non-zero exit code {ret.returncode}")
 
         return ret.stdout.decode('utf-8').strip()
-    except (UnicodeDecodeError, FileNotFoundError):
+    except (UnicodeDecodeError, ValueError, FileNotFoundError):
         print("git not found, timestamp based on current time")
         return str(datetime.datetime.now())
 
