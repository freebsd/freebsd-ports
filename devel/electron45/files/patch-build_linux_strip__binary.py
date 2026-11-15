--- build/linux/strip_binary.py.orig	2026-10-19 21:50:55 UTC
+++ build/linux/strip_binary.py
@@ -10,6 +10,7 @@ def main() -> int:
 
 
 def main() -> int:
+    return 0
     parser = argparse.ArgumentParser(
         description="Strip binary using LLVM tools."
     )
