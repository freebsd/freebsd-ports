--- freqtrade/worker.py.orig	2023-02-13 07:56:01 UTC
+++ freqtrade/worker.py
@@ -7,7 +7,7 @@ import traceback
 from os import getpid
 from typing import Any, Callable, Dict, Optional
 
-import sdnotify
+#import sdnotify
 
 from freqtrade import __version__
 from freqtrade.configuration import Configuration
@@ -57,8 +57,9 @@ class Worker:
                                                    PROCESS_THROTTLE_SECS)
         self._heartbeat_interval = internals_config.get('heartbeat_interval', 60)
 
-        self._sd_notify = sdnotify.SystemdNotifier() if \
-            self._config.get('internals', {}).get('sd_notify', False) else None
+        #self._sd_notify = sdnotify.SystemdNotifier() if \
+        #    self._config.get('internals', {}).get('sd_notify', False) else None
+        self._sd_notify = None
 
     def _notify(self, message: str) -> None:
         """
