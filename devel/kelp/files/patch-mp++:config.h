--- mp++/config.h.orig	Tue Dec  5 17:55:10 2000
+++ mp++/config.h	Tue Dec  5 17:56:20 2000
@@ -3,6 +3,18 @@
 #ifndef CONFIG_H_Included
 #define CONFIG_H_Included
 
+#if (defined(__linux__) || defined(__sparc__) || defined(__FreeBSD__))
+#  define PASTE_H "paste.h"
+#else
+#  define PASTE_H <generic.h>
+#endif
+
+#endif // CONFIG_H_Included
+//  This is a basic configuration header file to handle machine variations.
+
+#ifndef CONFIG_H_Included
+#define CONFIG_H_Included
+
 #if (defined(__linux__) || defined(__sparc__)|| defined(_AIX))
 #  define PASTE_H "paste.h"
 #else
