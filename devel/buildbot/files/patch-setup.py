--- setup.py~	2017-03-28 21:19:34.000000000 +0000
+++ setup.py	2017-03-28 21:19:39.875072000 +0000
@@ -180,6 +180,7 @@
         "buildbot.schedulers",
         "buildbot.scripts",
         "buildbot.secrets",
+        "buildbot.secrets.providers",
         "buildbot.statistics",
         "buildbot.statistics.storage_backends",
         "buildbot.status",
@@ -453,7 +453,6 @@
     'txaio ' + txaio_ver,
     'autobahn ' + autobahn_ver,
     'PyJWT',
-    'distro'
 ]
 
 # Unit test dependencies.
