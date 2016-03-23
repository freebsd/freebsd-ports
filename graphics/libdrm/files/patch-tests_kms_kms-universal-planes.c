--- tests/kms/kms-universal-planes.c.orig	2016-02-15 12:05:56.305353000 +0100
+++ tests/kms/kms-universal-planes.c	2016-02-15 12:06:11.194126000 +0100
@@ -32,6 +32,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <unistd.h>
+#include <sys/select.h>
 
 #include <drm_fourcc.h>
 #include "xf86drm.h"
