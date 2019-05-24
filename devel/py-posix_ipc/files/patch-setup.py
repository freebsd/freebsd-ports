--- setup.py.orig	2018-08-07 00:29:38 UTC
+++ setup.py
@@ -39,6 +39,7 @@ license = "http://creativecommons.org/licenses/BSD/"
 keywords = "ipc inter-process communication semaphore shared memory shm message queue"
 
 libraries = []
+test_suite = "tests"
 
 d = prober.probe()
 
@@ -69,5 +70,6 @@ distutools.setup(name=name,
                  classifiers=classifiers,
                  license=license,
                  keywords=keywords,
-                 ext_modules=ext_modules
+                 ext_modules=ext_modules,
+                 test_suite=test_suite
                  )
