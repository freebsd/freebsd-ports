--- src/battery.c.orig	Mon Aug 12 14:07:55 2002
+++ src/battery.c	Mon Aug 12 14:16:49 2002
@@ -70,10 +70,11 @@
 #include <gdk-pixbuf/gdk-pixbuf.h>
 #include <gtk/gtk.h>
 
-#ifdef __FreeBSD__
+/* APM is i386-specific. */
+#if defined(__FreeBSD__) && defined(__i386__)
 #include <fcntl.h>
 #include <machine/apm_bios.h>
-#endif /* __FreeBSD__ */
+#endif /* __FreeBSD__ && __i386__ */
 
 #include "../config.h"
 #include "battery.h"
@@ -237,7 +238,7 @@
 #endif /* Linux */
 
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) && defined(__i386__)
 /*
  * Return TRUE on success, FALSE on error.
  */
@@ -311,7 +312,7 @@
   close (fd);
   return TRUE;
 }
-#endif /* __FreeBSD__ */
+#endif /* __FreeBSD__ && __i386__ */
 
 
 /*
@@ -326,7 +327,7 @@
     }
 #if defined(__linux__)
   return battery_get_values_linux (&batlevel, &batloading);
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) && defined(__i386__)
   return battery_get_values_fbsd (&batlevel, &batloading);
 #else
   /* add support for your favourite OS here */
