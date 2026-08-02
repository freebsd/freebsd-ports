-- Remove shebang from rust_shim.py as it is not a standalone script
-- and should not be executed directly

--- cibuildwheel/resources/android/rust_shim.py.orig	2026-08-02 12:34:00.000000000 -0700
+++ cibuildwheel/resources/android/rust_shim.py
@@ -1,4 +1,3 @@
-#!/usr/bin/env python3
 
 import os
 import shutil
