--- setup.py.orig	2018-05-12 17:29:03 UTC
+++ setup.py
@@ -168,6 +168,7 @@ assert isinstance(version, str)
 
 def get_hg_changeset():
     """Get the Mercurial changeset id."""
+    return None
     try:
         output = subprocess.check_output(['hg', 'parent', '--template', '{node} {date}'],
                                          shell=False)
@@ -179,6 +180,7 @@ def get_hg_changeset():
 
 def get_git_changeset():
     """Get the Git changeset id."""
+    return None
     try:
         output = subprocess.check_output(['git', 'log', '--pretty=%H %ct', '-1'],
                                          shell=False)
