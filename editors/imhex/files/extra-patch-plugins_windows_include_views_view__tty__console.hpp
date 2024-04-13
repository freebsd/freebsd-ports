--- plugins/windows/include/views/view_tty_console.hpp.orig	2022-10-15 14:50:11 UTC
+++ plugins/windows/include/views/view_tty_console.hpp
@@ -1,6 +1,7 @@
 #pragma once
 
 #include <hex/ui/view.hpp>
+#include <jthread.hpp>
 
 #include <windows.h>
 
