--- Lib/test/regrtest.py.orig	2011-09-03 18:16:43.000000000 +0200
+++ Lib/test/regrtest.py	2011-10-28 11:26:04.000000000 +0200
@@ -1522,6 +1522,8 @@
 _expectations['freebsd6'] = _expectations['freebsd4']
 _expectations['freebsd7'] = _expectations['freebsd4']
 _expectations['freebsd8'] = _expectations['freebsd4']
+_expectations['freebsd9'] = _expectations['freebsd4']
+_expectations['freebsd10'] = _expectations['freebsd4']
 
 class _ExpectedSkips:
     def __init__(self):
