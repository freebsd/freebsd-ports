--- ./lib/carbon/util.py.orig	2013-12-22 16:45:46.061449090 +0000
+++ ./lib/carbon/util.py	2013-12-22 16:46:00.326083639 +0000
@@ -18,7 +18,7 @@
 from time import sleep, time
 from twisted.python.util import initgroups
 from twisted.scripts.twistd import runApp
-from twisted.scripts._twistd_unix import daemonize
+from django.utils import daemonize
 
 
 daemonize = daemonize  # Backwards compatibility
