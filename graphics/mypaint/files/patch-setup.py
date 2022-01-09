--- setup.py.orig	2022-01-09 11:24:00 UTC
+++ setup.py
@@ -867,7 +867,6 @@ def get_ext_modules():
         '-Wall',
         '-Wno-sign-compare',
         '-Wno-write-strings',
-        '-D_POSIX_C_SOURCE=200809L',
         "-DNO_TESTS",  # FIXME: we're building against shared libmypaint now
         '-g',  # always include symbols, for profiling
     ]
