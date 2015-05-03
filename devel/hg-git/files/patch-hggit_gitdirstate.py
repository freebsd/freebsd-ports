--- hggit/gitdirstate.py.orig	2014-05-09 14:26:29 UTC
+++ hggit/gitdirstate.py
@@ -161,7 +161,11 @@ class gitdirstate(dirstate.dirstate):
         results, work, dirsnotfound = self._walkexplicit(match, subrepos)
 
         skipstep3 = skipstep3 and not (work or dirsnotfound)
-        work = [d for d in work if not dirignore(d)]
+        if work and isinstance(work[0], tuple):
+            # Mercurial >= 3.3.3
+            work = [nd for nd, d in work if not dirignore(d)]
+        else:
+            work = [d for d in work if not dirignore(d)]
         wadd = work.append
 
         # step 2: visit subdirectories
