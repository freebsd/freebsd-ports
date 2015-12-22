--- zfuncs.h.orig	2015-05-01 09:40:38 UTC
+++ zfuncs.h
@@ -22,17 +22,18 @@
 
 //     zfuncs.h   version  v.6.1
 
-#include <sys/sysinfo.h>
+//#include <sys/sysinfo.h>
 #include <sys/time.h>
 #include <sys/stat.h>
 #include <sys/resource.h>
 #include <sys/file.h>
 #include <sys/utsname.h>
-#include <malloc.h>
+//#include <malloc.h>
 #include <errno.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
+#include <sys/wait.h>
 #include <string.h>
 #include <ctype.h>
 #include <math.h>
