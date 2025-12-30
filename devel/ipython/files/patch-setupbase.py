--- setupbase.py.orig	2025-01-29 09:57:23 UTC
+++ setupbase.py
@@ -93,10 +93,7 @@ def find_data_files():
     Just man pages at this point.
     """
 
-    if "freebsd" in sys.platform:
-        manpagebase = Path("man") / "man1"
-    else:
-        manpagebase = Path("share") / "man" / "man1"
+    manpagebase = Path("share") / "man" / "man1"
 
     # Simple file lists can be made by hand
     manpages = [f for f in Path("docs/man").glob("*.1.gz") if f.is_file()]
