--- gitless/core.py.orig	2019-05-28 19:39:17 UTC
+++ gitless/core.py
@@ -58,6 +58,13 @@ GL_STATUS_TRACKED = 2
 GL_STATUS_IGNORED = 3
 
 
+def error_on_none(path):
+  """Raise a KeyError if the ```path``` argument is None."""
+  if path is None:
+    raise KeyError('path')
+  return path
+
+
 def init_repository(url=None):
   """Creates a new Gitless's repository in the cwd.
 
@@ -67,7 +74,7 @@ def init_repository(url=None):
   """
   cwd = os.getcwd()
   try:
-    pygit2.discover_repository(cwd)
+    error_on_none(pygit2.discover_repository(cwd))
     raise GlError('You are already in a Gitless repository')
   except KeyError:  # Expected
     if not url:
@@ -108,7 +115,7 @@ class Repository(object):
   def __init__(self):
     """Create a Repository out of the current working repository."""
     try:
-      path = pygit2.discover_repository(os.getcwd())
+      path = error_on_none(pygit2.discover_repository(os.getcwd()))
     except KeyError:
       raise NotInRepoError('You are not in a Gitless\'s repository')
 
@@ -1333,10 +1340,18 @@ OpCb = collections.namedtuple(
     'OpCb', ['apply_ok', 'apply_err', 'save', 'restore_ok'])
 
 def stdout(p):
-  return p.stdout.decode(ENCODING)
+  try:
+      pstdout = p.stdout.decode(ENCODING)
+  except AttributeError:
+      pstdout = p.stdout
+  return pstdout
 
 def stderr(p):
-  return p.stderr.decode(ENCODING)
+  try:
+      pstderr = p.stderr.decode(ENCODING)
+  except AttributeError:
+      pstderr = p.stderr
+  return pstderr
 
 def walker(git_repo, target, reverse):
   flags = pygit2.GIT_SORT_TOPOLOGICAL | pygit2.GIT_SORT_TIME
