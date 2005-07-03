--- ./lib/as_system.py.orig	Tue Jun 28 12:56:13 2005
+++ ./lib/as_system.py	Sun Jul  3 18:02:43 2005
@@ -597,7 +597,7 @@
          self._mess(_('error getting environment'), '<E>_ABNORMAL_ABORT')
          return
       # read profile and dump modified environment
-      iret, out = self.Shell('sh -c "source '+profile+' ; env"')
+      iret, out = self.Shell('sh -c ". '+profile+' ; env"')
       env_prof = env2dict(out)
       if iret<>0:
          self._mess(_('error reading profile : %s') % profile,
