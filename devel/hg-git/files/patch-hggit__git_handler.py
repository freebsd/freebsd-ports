--- ./hggit/git_handler.py.orig	2013-03-24 22:35:51.000000000 +0100
+++ ./hggit/git_handler.py	2013-10-05 10:40:01.222598222 +0200
@@ -1034,7 +1034,7 @@
                         and ( ref.startswith('refs/heads/') or ref.startswith('refs/tags/') ) ]
             want = [x for x in want if x not in self.git]
             return want
-        f, commit = self.git.object_store.add_pack()
+        f, commit = self.git.object_store.add_pack()[:2]
         try:
             try:
                 progress = GitProgress(self.ui)
