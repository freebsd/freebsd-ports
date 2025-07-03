--- pythran/dist.py.orig	2024-10-17 07:42:48 UTC
+++ pythran/dist.py
@@ -92,7 +92,7 @@ class PythranBuildExtMixIn(object):
                     return find_exe(exe, *args, **kwargs)
 
                 msvc._find_exe = _find_exe
-            except ImportError:
+            except (AttributeError, ImportError):
                 pass
 
         # In general, distutils uses -Wstrict-prototypes, but this option
