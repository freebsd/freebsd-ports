--- include/sane/sane.h.orig	2009-04-24 04:59:23.000000000 +0900
+++ include/sane/sane.h	2009-05-13 15:15:50.000000000 +0900
@@ -115,6 +115,7 @@
 #define SANE_CAP_AUTOMATIC		(1 << 4)
 #define SANE_CAP_INACTIVE		(1 << 5)
 #define SANE_CAP_ADVANCED		(1 << 6)
+#define SANE_CAP_ALWAYS_SETTABLE	(1 << 7)
 
 #define SANE_OPTION_IS_ACTIVE(cap)	(((cap) & SANE_CAP_INACTIVE) == 0)
 #define SANE_OPTION_IS_SETTABLE(cap)	(((cap) & SANE_CAP_SOFT_SELECT) != 0)
