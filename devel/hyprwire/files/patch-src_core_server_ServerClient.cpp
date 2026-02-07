--- src/core/server/ServerClient.cpp.orig	2025-11-23 08:04:14 UTC
+++ src/core/server/ServerClient.cpp
@@ -7,6 +7,8 @@
 #include "../../helpers/Log.hpp"
 #include "../../Macros.hpp"
 
+#include <unistd.h>
+
 #include <hyprwire/core/implementation/ServerImpl.hpp>
 #include <hyprwire/core/implementation/Spec.hpp>
 
