--- windoze.c.orig	Sun Aug 22 20:15:00 1999
+++ windoze.c	Sat Jan  6 21:23:35 2001
@@ -15,6 +15,9 @@
 #include <errno.h>
 #include <stdio.h>
 #include <slang.h>
+#ifdef KANJI
+#include <slkanji.h>
+#endif
 #include <time.h>
 #include <string.h>
 #include "slirc.h"
@@ -124,7 +127,19 @@
    while (*p && isspace(*p)) p++ ;
    q = p;
    if (*p) {
+#ifdef KANJI
+      for (q = p; q < (p+tw); q++) {
+	 if(iskanji(*q)) {
+	    q++;
+	 }
+      }
+      if (q > (p+tw)) {
+	 q -= 2;
+      }
+      if (q > txth) q = txth;
+#else
       q += tw; if (q > txth) q = txth;
+#endif
       /* go back up to 1/3 of text-width looking for a word-break */
       if (*q && !isspace(*q)) {
 	char *r,*rlow;
@@ -256,6 +271,11 @@
       } else if (*cp == CTRL_O) {
 	 bold = 0;
 	 SLsmg_set_color(ColNorm);
+#ifdef KANJI
+      } else if (iskanji(*cp)){
+	 SLsmg_write_nstring(cp,2);
+	 cp++;
+#endif
       } else if (*cp != '')
 	   SLsmg_write_char(*cp);
    }
