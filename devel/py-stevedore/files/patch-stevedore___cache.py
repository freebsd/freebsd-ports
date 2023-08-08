--- stevedore/_cache.py.orig	2023-02-10 18:29:38 UTC
+++ stevedore/_cache.py
@@ -15,7 +15,6 @@
 import errno
 import glob
 import hashlib
-import importlib.metadata as importlib_metadata
 import itertools
 import json
 import logging
@@ -24,6 +23,14 @@ import os.path
 import struct
 import sys
 
+# only until 2023-06-23 when lang/python37 expires
+# https://opendev.org/openstack/stevedore/commit/ccd17543a37143913e886f9306be10d40260fdf3
+try:
+    # For python 3.8 and later
+    import importlib.metadata as importlib_metadata
+except ImportError:
+    # For everyone else
+    import importlib_metadata
 
 log = logging.getLogger('stevedore._cache')
 
