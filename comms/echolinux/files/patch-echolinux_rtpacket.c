--- echolinux/rtpacket.c.orig	2002-12-22 03:10:48 UTC
+++ echolinux/rtpacket.c
@@ -1,4 +1,8 @@
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <strings.h>
+#include <arpa/inet.h>
 #include "rtp.h"
 #include "rtpacket.h"
 
@@ -11,6 +15,16 @@ extern char callsign[], name[];
 
 /*************** RTP_MAKE_SDES *************/
 
+static    unsigned char *ap;
+static    void addSDES(unsigned char item, char *text)
+{
+    int l;
+    *ap++ = item;
+    *ap++ = l = strlen(text);
+    bcopy(text, ap, l);
+    ap += l;
+}
+
 int rtp_make_sdes(pkt, ssrc_i, strict)
   char **pkt;
   unsigned long ssrc_i;
@@ -19,20 +33,11 @@ int rtp_make_sdes(pkt, ssrc_i, strict)
     unsigned char zp[1500];
     unsigned char *p = zp;
     rtcp_t *rp;
-    unsigned char *ap;
     char *sp, *ep;
     char line[180];
     int l, hl, i;
     struct passwd *pw;
     char s[256], ev[1024];
-
-    void addSDES(unsigned char item, char *text){
-        *ap++ = item;
-        *ap++ = l = strlen(text);
-        bcopy(text, ap, l);
-        ap += l;
-    }
-
 
     hl = 0;
     if (strict) {
