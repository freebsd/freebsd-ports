Description: Drop the Python 2 exceptions import from the verinfo command.
Issue ID: https://github.com/tpltnt/pyutil/pull/15
Changeset: none (pyutil 3.4.1 still imports exceptions)
TODO: Submit upstream; drop once a release includes the fix.

--- pyutil/scripts/verinfo.py.orig	2026-05-31 06:43:56 UTC
+++ pyutil/scripts/verinfo.py
@@ -1,8 +1,7 @@
 #!/usr/bin/env python
 # -*- coding: utf-8-with-signature-unix; fill-column: 77 -*-
 # -*- indent-tabs-mode: nil -*-
-import exceptions
-class UsageError(exceptions.Exception): pass
+class UsageError(Exception): pass
 
 import sys
 from importlib.metadata import version, distribution, PackageNotFoundError
