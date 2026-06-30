--- breezy/git/mapping.py.orig	2022-01-23 23:17:50 UTC
+++ breezy/git/mapping.py
@@ -160,7 +160,7 @@ class BzrGitMapping(foreign.VcsMapping):
         super(BzrGitMapping, self).__init__(foreign_vcs_git)
 
     def __eq__(self, other):
-        return (type(self) == type(other)
+        return (type(self) is type(other)
                 and self.revid_prefix == other.revid_prefix)
 
     @classmethod
