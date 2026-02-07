--- src/libpasori_command.c.orig	Mon Mar 20 09:12:58 2006
+++ src/libpasori_command.c	Fri Jan 19 01:54:43 2007
@@ -1,6 +1,7 @@
 /* pasori commands */
 #include "libpasori_liblocal.h"
 #include <stdlib.h>
+#include <string.h>
 
 /* FIXME: UNKNOWN CONSTANTS */
 const uint8 PASORI_INIT0[] = {0x62,0x01,0x82};
@@ -24,7 +25,6 @@
 void /* FIXME: return errorcode */
 pasori_packet_write(pasori* p,uint8* data,int size){ /* RAW Packet SEND */
 	uint8 cmd[256];
-	uint8 recv[256];
 	uint8 sum;
 	int i;
 	sum = 0;
@@ -81,6 +81,7 @@
 	s = recv[3];
 	/* FIXME:calc checksum */
 	/* FIXME:check buffer size */
+	(void)size;
 	/* FIXME:check msgid */
 	s--;
 	memcpy(data,&recv[7],s);
@@ -95,6 +96,9 @@
 	uint8 resp[256];
 	uint8 blklist[2];
 	int i;
+
+	(void)mode; /* FIXME: what is this argument? */
+
 	blklist[0] = 0;
 	blklist[1] = addr;
 	blklist[0] |= 0x80; /* element size == 2 */
@@ -124,7 +128,6 @@
 /* INIT */
 int
 pasori_init(pasori *p){
-	uint8 recv[256];
 	pasori_test(p,PASORI_INIT0,sizeof(PASORI_INIT0));
 	pasori_test(p,PASORI_INIT1,sizeof(PASORI_INIT1));
 	pasori_test(p,PASORI_INIT2,sizeof(PASORI_INIT2));
