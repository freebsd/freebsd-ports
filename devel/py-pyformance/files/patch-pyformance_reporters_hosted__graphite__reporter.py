Description: Port the hosted Graphite reporter to Python 3 (urllib.request,
  base64.b64encode, bytes, correct relative imports).
Issue ID: none
Changeset: none
TODO: Upstream is dead (no commits since 2018-12); keep locally.

--- pyformance/reporters/hosted_graphite_reporter.py.orig	2017-10-08 11:44:59 UTC
+++ pyformance/reporters/hosted_graphite_reporter.py
@@ -1,11 +1,14 @@ import sys
 # -*- coding: utf-8 -*-
 from __future__ import print_function
 import sys
-import urllib2
+try:
+    import urllib.request as urllib2
+except ImportError:
+    import urllib2
 import base64
 
-from .meters import Counter, Histogram, Meter, Timer
-from .registry import MetricsRegistry
+from ..meters import Counter, Histogram, Meter, Timer
+from ..registry import MetricsRegistry
 from .reporter import Reporter
 
 
@@ -28,9 +31,9 @@ class HostedGraphiteReporter(Reporter):
         if metrics:
             try:
                 # XXX: better use http-keepalive/pipelining somehow?
-                request = urllib2.Request(self.url, metrics)
+                request = urllib2.Request(self.url, metrics.encode("utf-8"))
                 request.add_header("Authorization", "Basic %s" %
-                                   base64.encodestring(self.api_key).strip())
+                                   base64.b64encode(self.api_key.encode("utf-8")).decode("ascii"))
                 result = urllib2.urlopen(request)
             except Exception as e:
                 print(e, file=sys.stderr)
