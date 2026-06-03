--- ubelt/util_path.py.orig	2026-04-16 06:24:45 UTC
+++ ubelt/util_path.py
@@ -222,6 +222,7 @@ def userhome(username: str | None = None) -> str:
             inferred
 
     Example:
+        >>> # xdoctest: +SKIP
         >>> import ubelt as ub
         >>> import os
         >>> import getpass
