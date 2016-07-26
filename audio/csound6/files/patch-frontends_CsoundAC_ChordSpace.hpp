--- frontends/CsoundAC/ChordSpace.hpp.orig	2015-09-29 11:13:28 UTC
+++ frontends/CsoundAC/ChordSpace.hpp
@@ -29,6 +29,7 @@
 #include <climits>
 #include <cmath>
 #include <cstdarg>
+#include <cstdio>
 #include <eigen3/Eigen/Dense>
 #include "Event.hpp"
 #include <iostream>
@@ -554,7 +555,7 @@ public:
 		char buffer[0x1000];
 		std::stringstream stream;
 		for (size_t voice = 0; voice < voices(); ++voice) {
-			std::snprintf(buffer, 0x100, "%12.7f", getPitch(voice));
+			snprintf(buffer, 0x100, "%12.7f", getPitch(voice));
 			if (voice > 0) {
 				stream << " ";
 			}
