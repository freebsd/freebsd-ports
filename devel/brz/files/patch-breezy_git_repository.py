--- breezy/git/repository.py.orig	2022-02-02 23:16:49 UTC
+++ breezy/git/repository.py
@@ -352,7 +352,7 @@ class LocalGitRepository(GitRepository):
         return list(ret)
 
     def _get_parents(self, revid, no_alternates=False):
-        if type(revid) != bytes:
+        if not isinstance(revid, bytes):
             raise ValueError
         try:
             (hexsha, mapping) = self.lookup_bzr_revision_id(revid)
