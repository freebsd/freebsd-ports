--- t_prepro.h.orig	Wed May 16 15:33:34 2001
+++ t_prepro.h	Sat Jan 18 18:19:25 2003
@@ -34,12 +34,12 @@
 #define __PREPRO_H__
 
 #ifdef FREEBSD
-#include <machine/types.h>
+//#include <machine/types.h>
 #endif
 typedef struct section_s section_t;
-#ifndef FREEBSD
+#if __FreeBSD__ > 4
 typedef struct label_s label_t;
 #endif
 #define SECTIONSLOTS 17
 #define LABELSLOTS 17
 
