--- src/genlib/util/gmtdate.cpp.orig	Fri Jun 15 08:22:16 2001
+++ src/genlib/util/gmtdate.cpp	Sat Aug  3 16:29:39 2002
@@ -41,7 +41,7 @@
 #include <stdlib.h>
 #include <ctype.h>
 #include <string.h>
-#include <values.h>
+#include <machine/limits.h>
 #include <genlib/util/gmtdate.h>
 #include <genlib/util/miscexceptions.h>
 
@@ -254,7 +254,7 @@
     
     val = (int)strtol( str, &endptr, 10 );
     
-    if ( val < 0 || val == MAXINT )
+    if ( val < 0 || val == INT_MAX )
     {
         return -1;
     }
