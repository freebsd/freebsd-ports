--- Kaid.h	Sat Feb  5 22:05:08 2005
--- Kaid.h	Wed Mar  2 08:54:08 2005
@@ -4,23 +4,24 @@
 #include <vector>
 #include <string>
 #include <iterator>
+#ifndef PLATFORM_freebsd
 #include <locale>
+#endif
 #include <string>
 #include <algorithm>
 #include <cctype>
 
 #include <sys/time.h>
 
-#define CONFIG_FILE         "kaid.conf"
 #define	AUTHOR				"Mineiro"
-#ifndef PLATFORM_macosx_jaguar
-	#ifdef OPENWRT
-		#define PLATFORM	"KaiStation"
-	#else
-		#define PLATFORM	"Linux"
-	#endif
-#else
+#if defined(PLATFORM_macosx_jaguar)
 #define PLATFORM			"Mac OSX"
+#elif defined(PLATFORM_freebsd)
+#define PLATFORM			"FreeBSD"
+#elif defined(OPENWRT)
+#define PLATFORM			"KaiStation"
+#else
+#define PLATFORM			"Linux"
 #endif
 
 using namespace std;
