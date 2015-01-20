
$FreeBSD$

--- src/slonik/slonik.c.orig
+++ src/slonik/slonik.c
@@ -22,7 +22,6 @@
 #include <ctype.h>
 #include <sys/types.h>
 #include <sys/wait.h>
-#include <alloca.h>
 #else
 #include <winsock2.h>
 #include <windows.h>
