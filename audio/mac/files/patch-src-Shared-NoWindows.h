--- src/Shared/NoWindows.h.orig	Tue May  3 10:05:03 2005
+++ src/Shared/NoWindows.h	Mon Nov 28 01:47:00 2005
@@ -65,7 +65,7 @@
 
 #include <locale.h> 
 
-#define _FPOSOFF(fp) ((long)(fp).__pos)
+#define _FPOSOFF(fp) ((long)(fp))
 #define MAX_PATH    260
 
 #ifndef _WAVEFORMATEX_
