--- src/rosdep2/sources_list.py.orig	2019-02-18 20:29:59 UTC
+++ src/rosdep2/sources_list.py
@@ -100,7 +100,7 @@ def get_sources_list_dir():
         # we can't use etc/ros because environment config does not carry over under sudo
         etc_ros = rospkg.get_etc_ros_dir()
     else:
-        etc_ros = '/etc/ros'
+        etc_ros = '/usr/local/etc/ros'
     # compute default system wide sources directory
     sys_sources_list_dir = os.path.join(etc_ros, 'rosdep', SOURCES_LIST_DIR)
     sources_list_dirs = get_sources_list_dirs(sys_sources_list_dir)
