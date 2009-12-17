--- libsee/system.c.orig	2009-12-17 14:05:43.000000000 -0800
+++ libsee/system.c	2009-12-17 14:07:20.000000000 -0800
@@ -70,6 +70,8 @@
 #include "dprint.h"
 #include "platform.h"
 
+typedef	void * GC_PTR;
+
 /* Prototypes */
 static unsigned int simple_random_seed(void);
 #if HAVE_GC_MALLOC
