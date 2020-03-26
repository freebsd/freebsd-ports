--- src/support.cpp.orig	2020-03-17 23:31:20 UTC
+++ src/support.cpp
@@ -1,3 +1,5 @@
+#undef __GNUC__
+#define __GNUC__ 9
 //Copyright (c) 2019 Ultimaker B.V.
 //CuraEngine is released under the terms of the AGPLv3 or higher.
 
