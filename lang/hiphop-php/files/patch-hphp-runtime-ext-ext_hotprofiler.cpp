--- hphp/runtime/ext/ext_hotprofiler.cpp.orig	2013-07-21 13:34:10.135485647 +0200
+++ hphp/runtime/ext/ext_hotprofiler.cpp	2013-07-21 13:35:02.222657875 +0200
@@ -28,6 +28,7 @@
 
 #ifdef __FreeBSD__
 # include <sys/resource.h>
+# include <sys/param.h>
 # include <sys/cpuset.h>
 # define cpu_set_t cpuset_t
 # define SET_AFFINITY(pid, size, mask) \
