--- include/sane/sane.h.orig	2014-04-09 01:46:04 UTC
+++ include/sane/sane.h
@@ -115,6 +115,7 @@ SANE_Device;
 #define SANE_CAP_AUTOMATIC		(1 << 4)
 #define SANE_CAP_INACTIVE		(1 << 5)
 #define SANE_CAP_ADVANCED		(1 << 6)
+#define SANE_CAP_ALWAYS_SETTABLE	(1 << 7)
 
 #define SANE_OPTION_IS_ACTIVE(cap)	(((cap) & SANE_CAP_INACTIVE) == 0)
 #define SANE_OPTION_IS_SETTABLE(cap)	(((cap) & SANE_CAP_SOFT_SELECT) != 0)
