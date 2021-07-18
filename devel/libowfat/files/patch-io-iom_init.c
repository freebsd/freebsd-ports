Index: io/iom_init.c
===================================================================
RCS file: /cvs/libowfat/io/iom_init.c,v
retrieving revision 1.1
retrieving revision 1.2
diff -u -r1.1 -r1.2
--- io/iom_init.c	27 Mar 2018 02:23:00 -0000	1.1
+++ io/iom_init.c	21 Feb 2019 12:24:05 -0000	1.2
@@ -6,6 +6,8 @@
 #include <sys/types.h>
 #include <sys/event.h>
 #include <sys/time.h>
+#include <unistd.h>
+#include <fcntl.h>
 #endif
 
 int iom_init(iomux_t* c) {
