--- Lib/test/regrtest.py.orig	2011-06-11 17:48:50.000000000 +0200
+++ Lib/test/regrtest.py	2011-10-28 11:17:37.000000000 +0200
@@ -1203,6 +1203,8 @@
 _expectations['freebsd6'] = _expectations['freebsd4']
 _expectations['freebsd7'] = _expectations['freebsd4']
 _expectations['freebsd8'] = _expectations['freebsd4']
+_expectations['freebsd9'] = _expectations['freebsd4']
+_expectations['freebsd10'] = _expectations['freebsd4']
 
 class _ExpectedSkips:
     def __init__(self):
