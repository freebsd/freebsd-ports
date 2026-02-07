--- doc/rospkg_environment.rst.orig	2018-04-22 06:38:33 UTC
+++ doc/rospkg_environment.rst
@@ -95,9 +95,9 @@ default values when environment variable overrides are
 
 .. method:: get_etc_ros_dir([env=None]) -> str
 
-   Get directory location of ``/etc/ros`` directory.  The
+   Get directory location of ``/usr/local/etc/ros`` directory.  The
    :envvar:`ROS_ETC_DIR` environment variable has priority. If
-   :envvar:`ROS_ETC_DIR` is not set, ``/etc/ros`` is used.
+   :envvar:`ROS_ETC_DIR` is not set, ``/usr/local/etc/ros`` is used.
 
    :param env: override environment dictionary
    :return: path to use use for log file directory
