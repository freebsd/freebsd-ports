--- raphodo/utilities.py.orig	2020-04-17 01:22:23 UTC
+++ raphodo/utilities.py
@@ -82,10 +82,11 @@ if arrow_version >= parse_version('0.14.3') and arrow_
 # Linux specific code to ensure child processes exit when parent dies
 # See http://stackoverflow.com/questions/19447603/
 # how-to-kill-a-python-child-process-created-with-subprocess-check-output-when-t/
-libc = ctypes.CDLL("libc.so.6")
+libc = ctypes.CDLL("libc.so.7")
 def set_pdeathsig(sig = signal.SIGTERM):
     def callable():
-        return libc.prctl(1, sig)
+        return 0
+        #return libc.procctl(0, 0, 11, sig)
     return callable
 
 
@@ -201,8 +202,8 @@ def show_errors():
 # kilobytes, etc.
 suffixes = [_('B'), _('KB'), _('MB'), _('GB'), _('TB'), _('PB'), _('EB'), _('ZB'), _('YB')]
 
-def format_size_for_user(size_in_bytes: int, 
-                         zero_string: str='', 
+def format_size_for_user(size_in_bytes: int,
+                         zero_string: str='',
                          no_decimals: int=2) -> str:
     r"""
     Humanize display of bytes.
@@ -388,12 +389,12 @@ def find_mount_point(path: str) -> str:
     Find the mount point of a path
     See:
     http://stackoverflow.com/questions/4453602/how-to-find-the-mountpoint-a-file-resides-on
-    
+
     >>> print(find_mount_point('/crazy/path'))
     /
-    
-    :param path: 
-    :return: 
+
+    :param path:
+    :return:
     """
     path = os.path.realpath(path)
     while not os.path.ismount(path):
@@ -743,13 +744,13 @@ def _collect_duplicates(basenames, paths):
 
 def make_path_end_snippets_unique(*paths) -> List[str]:
     r"""
-    Make list of path ends unique given possible common path endings.  
-    
-    A snippet starts from the end of the path, in extreme cases possibly up the path start. 
+    Make list of path ends unique given possible common path endings.
 
+    A snippet starts from the end of the path, in extreme cases possibly up the path start.
+
     :param paths: sequence of paths to generate unique end snippets for
     :return: list of unique snippets
-    
+
     >>> p0 = '/home/damon/photos'
     >>> p1 = '/media/damon/backup1/photos'
     >>> p2 = '/media/damon/backup2/photos'
