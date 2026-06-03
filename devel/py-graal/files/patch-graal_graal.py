--- graal/graal.py.orig	2025-12-29 14:37:21 UTC
+++ graal/graal.py
@@ -47,7 +47,7 @@ DEFAULT_WORKTREE_PATH = '/tmp/worktrees/'
 
 CATEGORY_GRAAL = 'graal'
 DEFAULT_WORKTREE_PATH = '/tmp/worktrees/'
-GIT_EXEC_PATH = '/usr/bin/git'
+GIT_EXEC_PATH = '%%LOCALBASE%%/bin/git'
 
 logger = logging.getLogger(__name__)
 
