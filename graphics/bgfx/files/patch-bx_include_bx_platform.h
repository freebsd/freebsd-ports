--- bx/include/bx/platform.h.orig	2023-12-14 15:30:15 UTC
+++ bx/include/bx/platform.h
@@ -479,7 +479,7 @@ static_assert(false, "\n\n"
 #if BX_PLATFORM_BSD   \
  || BX_PLATFORM_HAIKU \
  || BX_PLATFORM_HURD
-static_assert(false, "\n\n"
+static_assert(true, "\n\n"
 	"\t** IMPORTANT! **\n\n"
 	"\tYou're compiling for unsupported platform!\n"
 	"\tIf you wish to support this platform, make your own fork, and modify code for _yourself_.\n"
