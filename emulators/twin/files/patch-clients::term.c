--- clients/term.c.orig	Thu Oct 24 05:35:38 2002
+++ clients/term.c	Tue Oct 29 14:12:54 2002
@@ -18,6 +18,8 @@
 #include <Tw/Twautoconf.h>
 
 #ifdef TW_HAVE_SYS_RESOURCE_H
+# include <sys/types.h>
+# include <sys/time.h>
 # include <sys/resource.h>
 #endif
 
