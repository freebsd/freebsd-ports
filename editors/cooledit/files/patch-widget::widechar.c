--- widget/widechar.c.orig	Sat Nov 27 17:46:03 2004
+++ widget/widechar.c	Wed Dec 15 01:17:59 2004
@@ -227,6 +227,7 @@
 static inline struct mb_rule apply_mb_rules_going_right (WEdit * edit, long byte_index, struct mb_rule mb_rule)
 {
 #ifdef HAVE_WCHAR_H
+#ifdef HAVE_MBRTOWC
     wchar_t wc;
     unsigned char p[16];
     int n;
@@ -252,6 +253,7 @@
     }
     mb_rule.end = 0;
     mb_rule.ch = -1;
+#endif
 #endif
     return mb_rule;
 }
