Missing include needed for std::abs; this caused a build error on 10.3 i386.

--- src/Components/Engine/AbstractEngine.cpp.orig	2017-12-31 13:34:19 UTC
+++ src/Components/Engine/AbstractEngine.cpp
@@ -29,6 +29,8 @@
 
 #include <gst/gst.h>
 
+#include <cstdlib>
+
 using Engine::Base;
 
 struct Base::Private
