Add missing defines and includes from removed ul.h

--- 3rdparty/joystick/js.h.orig	2018-05-30 23:24:08.180090000 +0200
+++ 3rdparty/joystick/js.h	2018-05-30 23:32:04.841896000 +0200
@@ -25,10 +25,20 @@
 #define __INCLUDED_JS_H__ 1
 #define JS_NEW
 
+#ifndef TRUE
+#define TRUE  1
+#define FALSE 0
+#endif
+
+#include <fcntl.h>
+#include <sys/param.h>
+
 #include <string>
 #include <cstring>
 #include <cstdlib>
 
+#include <simgear/props/props.hxx> /* for jsSetError and SG_WARN */
+
 #define _JS_MAX_AXES 16
 #define _JS_MAX_BUTTONS 32
 #define _JS_MAX_HATS 4
