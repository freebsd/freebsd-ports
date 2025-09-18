--- build/linux/strip_binary.py.orig	2025-08-26 20:49:50 UTC
+++ build/linux/strip_binary.py
@@ -10,6 +10,7 @@ def main() -> int:
 
 
 def main() -> int:
+  return 0
   parser = argparse.ArgumentParser(description="Strip binary using LLVM tools.")
   parser.add_argument("--llvm-strip-binary-path",
                       help="Path to llvm-strip executable.")
