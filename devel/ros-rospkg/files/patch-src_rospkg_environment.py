--- src/rospkg/environment.py.orig	2018-04-22 06:39:05 UTC
+++ src/rospkg/environment.py
@@ -212,9 +212,9 @@ def on_ros_path(p, env=None):
 
 def get_etc_ros_dir(env=None):
     """
-    Get directory location of ``/etc/ros`` directory.  The
+    Get directory location of ``/usr/local/etc/ros`` directory.  The
     :envvar:`ROS_ETC_DIR` environment variable has priority. If
-    :envvar:`ROS_ETC_DIR` is not set, ``/etc/ros`` is used.
+    :envvar:`ROS_ETC_DIR` is not set, ``/usr/local/etc/ros`` is used.
 
     :param env: override environment dictionary
     :return: path to use use for log file directory
@@ -224,4 +224,4 @@ def get_etc_ros_dir(env=None):
     if ROS_ETC_DIR in env:
         return env[ROS_ETC_DIR]
     else:
-        return '/etc/ros'
+        return '/usr/local/etc/ros'
