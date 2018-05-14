In file included from openborscript.c:30:
In file included from source/openborscript/config.h:12:
In file included from source/scriptlib/Interpreter.h:11:
In file included from source/scriptlib/depends.h:13:
In file included from source/globals.h:24:
source/utils.h:65:59: error: unknown type name 'time_t'
void get_time_string(char buffer[], unsigned buffer_size, time_t timestamp, char* pattern); // ex. "%Y-%m-%d %H:%M:%S"
                                                          ^

--- source/utils.h.orig	2018-05-13 22:01:54 UTC
+++ source/utils.h
@@ -10,6 +10,7 @@
 #define UTILS_H
 
 // *** INCLUDES ***
+#include <time.h>
 #include "types.h"
 #include "stringptr.h"
 
