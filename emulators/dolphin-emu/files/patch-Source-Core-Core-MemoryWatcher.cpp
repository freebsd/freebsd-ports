Add missing header for memset() and strncpy()

--- Source/Core/Core/MemoryWatcher.cpp.orig	2016-12-02 06:09:55.416128767 +0000
+++ Source/Core/Core/MemoryWatcher.cpp	2016-12-02 06:10:39.359433048 +0000
@@ -2,6 +2,7 @@
 // Licensed under GPLv2+
 // Refer to the license.txt file included.
 
+#include <cstring>
 #include <fstream>
 #include <iostream>
 #include <memory>
