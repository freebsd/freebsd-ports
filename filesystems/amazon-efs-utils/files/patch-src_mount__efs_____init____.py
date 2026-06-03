--- src/mount_efs/__init__.py.orig	2026-04-17 08:53:11 UTC
+++ src/mount_efs/__init__.py
@@ -36,6 +36,7 @@ import sys
 import re
 import sys
 
+sys.path.insert(0, "/usr/local/lib/amazon/efs")
 from efs_utils_common.cloudwatch import bootstrap_cloudwatch_logging
 from efs_utils_common.config_utils import (
     bootstrap_logging,
