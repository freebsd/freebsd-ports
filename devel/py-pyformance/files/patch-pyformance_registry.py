Description: Make the RegexRegistry docstring raw so "\d" no longer raises
  SyntaxWarning (invalid escape sequence) on Python 3.12+.
Issue ID: none
Changeset: none
TODO: Upstream is dead (no commits since 2018-12); keep locally.

--- pyformance/registry.py.orig	2017-10-08 11:44:59 UTC
+++ pyformance/registry.py
@@ -220,7 +220,7 @@ class MetricsRegistry(object):
 
 class RegexRegistry(MetricsRegistry):
 
-    """
+    r"""
     A single interface used to gather metrics on a service. This class uses a regex to combine
     measures that match a pattern. For example, if you have a REST API, instead of defining
     a timer for each method, you can use a regex to capture all API calls and group them.
