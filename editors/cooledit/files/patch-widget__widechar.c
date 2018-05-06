--- widget/widechar.c.orig	2017-08-04 19:12:31 UTC
+++ widget/widechar.c
@@ -227,6 +227,7 @@ static inline struct mb_rule apply_mb_ru
 static inline struct mb_rule apply_mb_rules_going_right (WEdit * edit, long byte_index, struct mb_rule mb_rule)
 {
 #ifdef HAVE_WCHAR_H
+#ifdef HAVE_MBRTOWC
     wchar_t wc;
     unsigned char p[16];
     int n;
@@ -253,6 +254,7 @@ static inline struct mb_rule apply_mb_ru
     mb_rule.end = 0;
     mb_rule.ch = -1;
 #endif
+#endif
     return mb_rule;
 }
 
