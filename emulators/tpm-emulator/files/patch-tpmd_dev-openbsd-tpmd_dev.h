--- tpmd_dev/openbsd/tpmd_dev.h.orig	2010-07-06 06:21:20.000000000 +0900
+++ tpmd_dev/openbsd/tpmd_dev.h	2010-10-25 02:56:43.632557559 +0900
@@ -20,7 +20,7 @@
 
 #include "config.h"
 
-#define cdev_tpm_init(c,n) { \
+#define cdev_tpmd_init(c,n) { \
     dev_init(c,n,open),dev_init(c,n,close),dev_init(c,n,read), \
     dev_init(c,n,write), dev_init(c,n,ioctl),(dev_type_stop((*))) lkmenodev, \
     0,(dev_type_poll((*))) lkmenodev,(dev_type_mmap((*))) lkmenodev }
