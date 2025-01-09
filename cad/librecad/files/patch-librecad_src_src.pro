Fix version string.

--- librecad/src/src.pro.orig	2025-01-05 06:23:48 UTC
+++ librecad/src/src.pro
@@ -10,7 +10,7 @@ DEFINES -= JWW_WRITE_SUPPORT
 DEFINES += DWGSUPPORT
 DEFINES -= JWW_WRITE_SUPPORT
 
-LC_VERSION="2.2.1_rc4"
+LC_VERSION="2.2.1"
 VERSION=$${LC_VERSION}
 
 # Store intermedia stuff somewhere else
