--- record.c.orig	2001-08-14 20:10:46.000000000 +0800
+++ record.c	2011-09-05 15:09:11.000000000 +0800
@@ -31,14 +31,18 @@
 **	May 25, 2000 Ver 1.0
 */
 
-#include<stdio.h>
-#include<fcntl.h>
-#include<sys/types.h>
-#include<pwd.h>
-#include<ctype.h>
-#include<errno.h>
+#include <sys/types.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <unistd.h>
+#include <sys/stat.h>
+#include <fcntl.h>
+#include <pwd.h>
+#include <ctype.h>
+#include <errno.h>
 
-#include"record.h"
+#include "record.h"
+#include "xjump.h"
 
 #define FS	'\t'	/* field separator */
 
