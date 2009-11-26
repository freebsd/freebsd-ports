--- Lib/test/regrtest.py.orgi	2009-11-26 13:29:08.000000000 +0100
+++ Lib/test/regrtest.py	2009-11-26 13:29:37.000000000 +0100
@@ -1146,6 +1146,7 @@
 _expectations['freebsd6'] = _expectations['freebsd4']
 _expectations['freebsd7'] = _expectations['freebsd4']
 _expectations['freebsd8'] = _expectations['freebsd4']
+_expectations['freebsd9'] = _expectations['freebsd4']
 
 class _ExpectedSkips:
     def __init__(self):
