--- setup.py.orig	2022-07-16 16:20:52 UTC
+++ setup.py
@@ -23,7 +23,7 @@ prefer_system_libzstd = True
 prefer_system_libb2 = True
 
 # True: use the shared libxxhash (>= 0.6.5 [>= 0.7.2 on ARM]) from the system, False: use the bundled xxhash code
-prefer_system_libxxhash = True
+prefer_system_libxxhash = False
 
 # prefer_system_msgpack is another option, but you need to set it in src/borg/helpers.py.
 
