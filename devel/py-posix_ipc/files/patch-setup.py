--- setup.py.orig	2016-02-21 15:13:28 UTC
+++ setup.py
@@ -32,6 +32,7 @@ classifiers = [ "Development Status :: 5
                 "Topic :: Utilities" ]
 license = "http://creativecommons.org/licenses/BSD/"
 keywords = "ipc inter-process communication semaphore shared memory shm message queue"
+test_suite = "tests"
 
 libraries = [ ]
 
@@ -65,5 +66,6 @@ duc.setup(name = name,
           classifiers = classifiers,
           license = license,
           keywords = keywords,
-          ext_modules = ext_modules
+          ext_modules = ext_modules,
+          test_suite = test_suite,
          )
