--- setup.py.orig	2020-12-15 07:58:37 UTC
+++ setup.py
@@ -9,7 +9,7 @@ import Codeville
 from distutils.core import setup
 import shutil
 import sys
-assert sys.version >= '2', "Install Python 2.0 or greater"
+assert sys.version >= '3', "Install Python 3.0 or greater"
 
 scripts = ["cdv", "cdvserver", "cdvpasswd", "cdv-agent", "cdvupgrade"]
 plat_ext = []
