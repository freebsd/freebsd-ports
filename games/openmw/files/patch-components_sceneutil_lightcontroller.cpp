--- components/sceneutil/lightcontroller.cpp.orig	2016-01-12 16:11:28 UTC
+++ components/sceneutil/lightcontroller.cpp
@@ -2,6 +2,7 @@
 
 #include <cmath>
 
+#include <osg/observer_ptr>
 #include <osg/NodeVisitor>
 
 #include <components/sceneutil/lightmanager.hpp>
