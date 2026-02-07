--- multiqc/multiqc.py.orig	2024-11-12 20:25:32 UTC
+++ multiqc/multiqc.py
@@ -13,6 +13,13 @@ import rich_click as click
 from typing import Optional, Tuple
 
 import rich_click as click
+if 'LC_ALL' in os.environ and 'LANG' in os.environ:
+    import rich_click as click
+else:
+    print('multiqc: LC_ALL and LANG must be set to a UTF-8 character set')
+    print('in your environment in order for the click module to function.')
+    print('E.g. export LC_ALL=en_US.UTF-8 or setenv LC_ALL en_US.UTF-8')
+    sys.exit()
 
 from multiqc import config, report, validation
 from multiqc.core import log_and_rich, plugin_hooks
