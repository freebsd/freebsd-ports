--- build/linux/strip_binary.py.orig	2022-05-11 07:16:46 UTC
+++ build/linux/strip_binary.py
@@ -10,6 +10,7 @@ import sys
 
 
 def main():
+  return 0
   argparser = argparse.ArgumentParser(description='eu-strip binary.')
 
   argparser.add_argument('--eu-strip-binary-path', help='eu-strip path.')
