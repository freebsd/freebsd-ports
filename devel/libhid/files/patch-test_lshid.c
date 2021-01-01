--- test/lshid.c.orig	2009-03-07 20:30:14.000000000 +0300
+++ test/lshid.c	2009-03-07 20:30:20.000000000 +0300
@@ -23,6 +23,7 @@
 
 #include <hid.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 
 char *hid_id[32]; /* FIXME: 32 devices MAX */
