--- bx/include/bx/platform.h.orig	2023-08-02 05:50:26 UTC
+++ bx/include/bx/platform.h
@@ -464,7 +464,7 @@
 #if BX_PLATFORM_BSD   \
  || BX_PLATFORM_HAIKU \
  || BX_PLATFORM_HURD
-static_assert(false, "\n\n"
+static_assert(true, "\n\n"
 	"\t** IMPORTANT! **\n\n"
 	"\tYou're compiling for unsupported platform!\n"
 	"\tIf you wish to support this platform, make your own fork, and modify code for _yourself_.\n"
