Fixes the error: no member named 'round' in namespace 'std'

--- src/main/sdl2/renderbase.cpp.orig	2021-04-27 14:23:03 UTC
+++ src/main/sdl2/renderbase.cpp
@@ -1,5 +1,6 @@
 #include "renderbase.hpp"
 #include <iostream>
+#include <cmath>
 
 RenderBase::RenderBase()
 {
