Description: Import _thread instead of threading for
  start_new_thread()/interrupt_main(), and use range.
Issue ID: https://github.com/tpltnt/pyutil/pull/15
Changeset: none
TODO: Submit upstream; drop once a release includes the fix.

--- pyutil/benchutil.py.orig	2022-12-26 22:48:41 UTC
+++ pyutil/benchutil.py
@@ -93,7 +93,7 @@ from decimal import Decimal as D
 
 import cProfile, operator, time
 from decimal import Decimal as D
-import threading as thread
+import _thread as thread
 
 #from pyutil import jsonutil as json
 
@@ -107,7 +107,7 @@ def makeg(func):
 
 def makeg(func):
     def blah(n, func=func):
-        for i in xrange(n):
+        for i in range(n):
             func()
     return blah
 
