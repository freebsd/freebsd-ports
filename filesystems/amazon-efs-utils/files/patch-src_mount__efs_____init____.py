--- src/mount_efs/__init__.py.orig	2026-04-17 08:53:11 UTC
+++ src/mount_efs/__init__.py
@@ -34,6 +34,7 @@ import logging
 import logging
 import platform
 import re
 import sys

+sys.path.insert(0, "@@EFS_LIBDIR@@")
 from efs_utils_common.cloudwatch import bootstrap_cloudwatch_logging
 from efs_utils_common.config_utils import (
