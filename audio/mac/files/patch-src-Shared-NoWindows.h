--- src/Shared/NoWindows.h.orig	Wed May 12 09:00:17 2004
+++ src/Shared/NoWindows.h	Mon Aug  9 20:28:34 2004
@@ -50,7 +50,7 @@
 
 #include <locale.h> 
 
-#define _FPOSOFF(fp) ((long)(fp).__pos)
+#define _FPOSOFF(fp) ((long)(fp))
 #define MAX_PATH    260
 
 #ifndef _WAVEFORMATEX_
