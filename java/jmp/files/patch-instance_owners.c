$FreeBSD$

--- instance_owners.c	Tue May 13 20:28:40 2003
+++ instance_owners.c	Tue May 13 20:28:11 2003
@@ -11,6 +11,10 @@
 #include <jmp-config.h>
 #include <inttypes.h>
 
+#if __FreeBSD__ < 5
+#define PRId32 "d"
+#endif
+
 enum {
     INFO,
     NUM_COLUMNS
