--- main.c.orig	Fri Oct 25 14:15:16 2002
+++ main.c	Fri Oct 25 15:05:09 2002
@@ -518,6 +518,9 @@
 #ifndef SMALL
 		} else {
 			const char *buf;
+#ifdef ENHANCED_LIBEDIT
+			HistEvent ev;
+#endif
 			cursor_pos = NULL;
 
 			if ((buf = el_gets(el, &num)) == NULL || num == 0)
@@ -532,7 +535,11 @@
 			}
 			memcpy(line, buf, (size_t)num);
 			line[num] = '\0';
+#ifndef ENHANCED_LIBEDIT
 			history(hist, H_ENTER, buf);
+#else
+			history(hist, &ev, H_ENTER, buf);
+#endif
 		}
 #endif /* !SMALL */
 
