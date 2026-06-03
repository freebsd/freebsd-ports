-- add missing include for rand() function

--- src/Airwindows/XRegion.cpp.orig	2026-05-21 06:57:07 UTC
+++ src/Airwindows/XRegion.cpp
@@ -29,6 +29,7 @@
 
 #include "XRegion.hpp"
 #include <cstring>
+#include <stdlib.h> // for rand()
 
 XRegion::XRegion (const double rate) :
     rate (rate),
