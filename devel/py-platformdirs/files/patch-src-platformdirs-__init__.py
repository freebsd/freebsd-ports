Workaround for setuptools-scm 6.x

>>> import platformdirs
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
  File "/usr/local/lib/python3.9/site-packages/platformdirs/__init__.py", line 17, in <module>
    from .version import __version__
ImportError: cannot import name '__version__' from 'platformdirs.version' (/usr/local/lib/python3.9/site-packages/platformdirs/version.py)

Reference:	https://github.com/pypa/setuptools_scm/commit/b45e19f9f275a31873fd5e07faabef16fd0bbec0

--- src/platformdirs/__init__.py.orig	2020-02-02 00:00:00 UTC
+++ src/platformdirs/__init__.py
@@ -9,8 +9,8 @@ import sys
 from typing import TYPE_CHECKING
 
 from .api import PlatformDirsABC
-from .version import __version__
-from .version import __version_tuple__ as __version_info__
+from .version import version
+from .version import version_tuple as __version_info__
 
 if TYPE_CHECKING:
     from pathlib import Path
