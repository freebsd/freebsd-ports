--- v8/tools/run.py.orig	2022-05-25 04:04:43 UTC
+++ v8/tools/run.py
@@ -9,7 +9,7 @@ scripts."""
 import subprocess
 import sys
 
-result = subprocess.call(sys.argv[1:])
+sys.exit(subprocess.call(sys.argv[1:], env={"LD_LIBRARY_PATH":"${WRKSRC}/out/Release"}))
 if result != 0:
   # Windows error codes such as 0xC0000005 and 0xC0000409 are much easier
   # to recognize and differentiate in hex.
