--- src/libs/subsonic/impl/SubsonicResource.hpp.orig	2021-10-02 19:20:11 UTC
+++ src/libs/subsonic/impl/SubsonicResource.hpp
@@ -19,6 +19,8 @@
 #pragma once
 
 #include <string>
+#include <unordered_map>
+
 #include <Wt/WResource.h>
 #include <Wt/Http/Response.h>
 
