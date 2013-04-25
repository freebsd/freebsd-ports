--- ./buildbot/changes/manager.py.orig	2012-10-19 16:37:15.000000000 +0900
+++ ./buildbot/changes/manager.py	2012-10-22 15:43:23.000000000 +0900
@@ -65,7 +65,7 @@
                 src.setServiceParent(self)
 
         num_sources = len(list(self))
-        assert num_sources == len(new_config.change_sources)
+#        assert num_sources == len(new_config.change_sources)
         metrics.MetricCountEvent.log("num_sources", num_sources, absolute=True)
 
         # reconfig any newly-added change sources, as well as existing
