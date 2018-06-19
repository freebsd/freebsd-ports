webpage.cpp:80:89: error: invalid suffix on literal; C++11 requires a space between literal and identifier [-Wreserved-user-defined-literal]
#define CALLBACKS_OBJECT_INJECTION      INPAGE_CALL_NAME" = function() { return window."CALLBACKS_OBJECT_NAME".call.call(_phantom, Array.prototype.slice.call(arguments, 0)); };"
                                                                                        ^
webpage.cpp:81:57: error: invalid suffix on literal; C++11 requires a space between literal and identifier [-Wreserved-user-defined-literal]
#define CALLBACKS_OBJECT_PRESENT        "typeof(window."CALLBACKS_OBJECT_NAME") !== \"undefined\";"
                                                        ^

--- src/webpage.cpp.orig	2018-01-26 07:17:31 UTC
+++ src/webpage.cpp
@@ -77,8 +77,8 @@
 #define BLANK_HTML                      "<html><head></head><body></body></html>"
 #define CALLBACKS_OBJECT_NAME           "_phantom"
 #define INPAGE_CALL_NAME                "window.callPhantom"
-#define CALLBACKS_OBJECT_INJECTION      INPAGE_CALL_NAME" = function() { return window."CALLBACKS_OBJECT_NAME".call.call(_phantom, Array.prototype.slice.call(arguments, 0)); };"
-#define CALLBACKS_OBJECT_PRESENT        "typeof(window."CALLBACKS_OBJECT_NAME") !== \"undefined\";"
+#define CALLBACKS_OBJECT_INJECTION      INPAGE_CALL_NAME" = function() { return window." CALLBACKS_OBJECT_NAME".call.call(_phantom, Array.prototype.slice.call(arguments, 0)); };"
+#define CALLBACKS_OBJECT_PRESENT        "typeof(window." CALLBACKS_OBJECT_NAME") !== \"undefined\";"
 
 #define STDOUT_FILENAME "/dev/stdout"
 #define STDERR_FILENAME "/dev/stderr"
