-- add missing include for rand() function
-- https://github.com/sjaehn/BOops/issues/27

--- src/Airwindows/XRegion.cpp.orig	2026-05-21 06:47:54 UTC
+++ src/Airwindows/XRegion.cpp
@@ -29,6 +29,7 @@
 
 #include "XRegion.hpp"
 #include <cstring>
+#include <stdlib.h> // for rand()
 
 XRegion::XRegion (const double rate) :
     rate (rate),
