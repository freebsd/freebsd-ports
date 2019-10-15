Fixes unicode display correctly, this prevents crashing on opening
(kindle format files).

--- src/assets/KindleUnpack/kindleunpack.py.orig	2019-10-07 19:55:37 UTC
+++ src/assets/KindleUnpack/kindleunpack.py
@@ -952,8 +952,8 @@ def main(argv=unicode_argv()):
     global SPLIT_COMBO_MOBIS
 
     print("KindleUnpack v0.82")
-    print("   Based on initial mobipocket version Copyright © 2009 Charles M. Hannum <root@ihack.net>")
-    print("   Extensive Extensions and Improvements Copyright © 2009-2014 ")
+    print("   Based on initial mobipocket version Copyright © 2009 Charles M. Hannum <root@ihack.net>".encode("utf-8"))
+    print("   Extensive Extensions and Improvements Copyright © 2009-2014 ".encode("utf-8"))
     print("       by:  P. Durrant, K. Hendricks, S. Siebert, fandrieu, DiapDealer, nickredding, tkeo.")
     print("   This program is free software: you can redistribute it and/or modify")
     print("   it under the terms of the GNU General Public License as published by")
