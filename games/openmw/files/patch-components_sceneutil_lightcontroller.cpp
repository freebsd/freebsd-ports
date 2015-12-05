--- components/sceneutil/lightcontroller.cpp.orig	2015-11-24 02:42:35 UTC
+++ components/sceneutil/lightcontroller.cpp
@@ -2,6 +2,7 @@
 
 #include <cmath>
 
+#include <osg/observer_ptr>
 #include <osg/NodeVisitor>
 
 #include <components/sceneutil/lightmanager.hpp>
