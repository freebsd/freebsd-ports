
$FreeBSD$

--- resample.c.orig	Sat Oct 26 23:32:35 2002
+++ resample.c	Sat Oct 26 23:32:51 2002
@@ -22,7 +22,7 @@
 
 #include <math.h>
 #include <stdio.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "config.h"
 #include "common.h"
