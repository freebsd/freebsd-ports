--- faketalk.c.orig	Sat May 22 09:32:43 1993
+++ faketalk.c	Mon Jun 26 03:16:18 2000
@@ -10,7 +10,7 @@
 
 #include "bsd.h"
 
-#if	defined(TALK_43) || defined(TALK_42)
+#if	!defined(TALK_DISABLE) && (defined(TALK_43) || defined(TALK_42))
 
 # include	<stdio.h>
 # include	<string.h>
