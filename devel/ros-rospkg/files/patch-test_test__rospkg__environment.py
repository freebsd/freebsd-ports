--- test/test_rospkg_environment.py.orig	2018-04-22 06:39:46 UTC
+++ test/test_rospkg_environment.py
@@ -158,7 +158,7 @@ def test_get_etc_ros_dir():
     base = tempfile.gettempdir()
     etc_ros_dir = os.path.join(base, 'etc_ros_dir')
 
-    assert '/etc/ros' == get_etc_ros_dir(env={})
+    assert '/usr/local/etc/ros' == get_etc_ros_dir(env={})
 
     # ROS_ETC_DIR has precedence
     env = {ROS_ETC_DIR: etc_ros_dir}
