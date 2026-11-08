Description: Import Iterator from collections.abc (removed from collections in
  Python 3.10).
Issue ID: none
Changeset: none
TODO: Upstream is dead (no commits or releases since 2017-10); keep locally.

--- sqlalchemy_imageattach/file.py.orig	2017-10-06 17:09:47 UTC
+++ sqlalchemy_imageattach/file.py
@@ -4,7 +4,7 @@
 The file-like types which wraps/proxies an other file objects.
 
 """
-from collections import Iterator
+from collections.abc import Iterator
 import os
 
 __all__ = 'FileProxy', 'ReusableFileProxy', 'SeekableFileProxy'
