--- setup.py.orig	2026-04-06 19:13:32 UTC
+++ setup.py
@@ -11,7 +11,7 @@ def get_git_commit_id(n_digits=8) -> Optional[str]:
         # Decode bytes to string (Python 3.x)
         commit_id = commit_id.decode('utf-8')
         return commit_id[:n_digits]
-    except subprocess.CalledProcessError as e:
+    except (subprocess.CalledProcessError, FileNotFoundError, OSError) as e:
         print("Failed to get Git commit ID:", e)
         return None
 
