--- nspmod.h.orig	1995-09-16 06:50:32 UTC
+++ nspmod.h
@@ -3,6 +3,7 @@
 #endif
 
 typedef struct {
+    i15x bits;		/* -b # */
     i15x onlyCh;	/* -c # */
     i15x showEvents;	/* -e, -ee */
     u16x outRate;	/* -f # */
