--- poetry2setup.py.orig	2021-01-23 17:40:07 UTC
+++ poetry2setup.py
@@ -1,6 +1,6 @@
 from __future__ import print_function
 
-from poetry.core.utils._compat import Path
+from pathlib import Path
 from poetry.core.factory import Factory
 from poetry.core.masonry.builders.sdist import SdistBuilder
 
