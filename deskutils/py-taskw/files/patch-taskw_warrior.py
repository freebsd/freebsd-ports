--- taskw/warrior.py.orig	2021-09-09 11:19:46 UTC
+++ taskw/warrior.py
@@ -412,10 +412,10 @@ class TaskWarriorShellout(TaskWarriorBase):
     and https://github.com/ralphbean/taskw/issues/30 for more.
     """
     DEFAULT_CONFIG_OVERRIDES = {
+        'verbose': 'nothing',
         'json': {
             'array': 'TRUE'
         },
-        'verbose': 'nothing',
         'confirmation': 'no',
         'dependency': {
             'confirmation': 'no',
