--- lib-python/2.7/distutils/sysconfig_pypy.py.orig	2017-04-06 19:44:56 UTC
+++ lib-python/2.7/distutils/sysconfig_pypy.py
@@ -61,12 +61,12 @@ _config_vars = None
 def _init_posix():
     """Initialize the module as appropriate for POSIX systems."""
     g = {}
-    g['CC'] = "gcc -pthread"
-    g['CXX'] = "g++ -pthread"
+    g['CC'] = "cc -pthread"
+    g['CXX'] = "c++ -pthread"
     g['OPT'] = "-DNDEBUG -O2"
     g['CFLAGS'] = "-DNDEBUG -O2"
     g['CCSHARED'] = "-fPIC"
-    g['LDSHARED'] = "gcc -pthread -shared"
+    g['LDSHARED'] = "cc -pthread -shared"
     g['SO'] = [s[0] for s in imp.get_suffixes() if s[2] == imp.C_EXTENSION][0]
     g['AR'] = "ar"
     g['ARFLAGS'] = "rc"
