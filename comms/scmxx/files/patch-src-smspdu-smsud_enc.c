--- src/smspdu/smsud_enc.c.orig	Fri Jul  8 12:26:13 2005
+++ src/smspdu/smsud_enc.c	Thu Jul 14 18:00:19 2005
@@ -22,6 +22,11 @@
 #include <stdlib.h>
 #include <unistd.h>
 
+#include <limits.h>
+#ifndef UINT16_MAX
+#define UINT16_MAX USHRT_MAX
+#endif
+
 static
 uint16_t sms_new_sequence_id () {
   /* this does not have to be good random (linear would be ok)
