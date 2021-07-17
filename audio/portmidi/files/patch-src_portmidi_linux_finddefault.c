--- src/portmidi/linux/finddefault.c.orig	2021-07-17 02:14:06 UTC
+++ src/portmidi/linux/finddefault.c
@@ -5,6 +5,9 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
+#if defined(__FreeBSD__)
+#include <ctype.h>
+#endif
 #include "portmidi.h"
 
 #define STRING_MAX 256
@@ -27,7 +30,7 @@ int match_string(FILE *inf, char *s)
 
 
 /* 
-/* Parse preference files, find default device, search devices --
+ * Parse preference files, find default device, search devices --
  */
 PmDeviceID find_default_device(char *path, int input, PmDeviceID id)
 /* path -- the name of the preference we are searching for
