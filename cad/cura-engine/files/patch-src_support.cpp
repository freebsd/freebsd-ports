--- src/support.cpp.orig	2022-01-24 15:11:50 UTC
+++ src/support.cpp
@@ -1,3 +1,5 @@
+#undef __GNUC__
+#define __GNUC__ 9
 //Copyright (c) 2021 Ultimaker B.V.
 //CuraEngine is released under the terms of the AGPLv3 or higher.
 
