--- src/libpasori_com_libusb.c.orig	2006-03-20 09:12:58.000000000 +0900
+++ src/libpasori_com_libusb.c	2009-03-09 03:11:29.000000000 +0900
@@ -1,13 +1,14 @@
 /* libpasori communicate LIBUSB ver. */
 
+#include <stdlib.h>
 #include "libpasori_liblocal.h"
-#include <usb.h>
 
 #define PASORIUSB_VENDOR 0x054c
-#define PASORIUSB_PRODUCT 0x01bb
+#define PASORIUSB_PRODUCT_RC_S310        0x006c
+#define PASORIUSB_PRODUCT_RC_S320        0x01bb
 
 void dbg_dump(unsigned char *b,unsigned int size){
-	int i;
+	unsigned int i;
 	if(size > 255) size = 255;
 	for(i=0;i!=size;i++){
 		Log("%02X ",b[i]);
@@ -25,8 +26,8 @@
 pasori* pasori_open(char *p){ /* FIXME: unused arg. */
 	struct usb_bus *bus;
 	struct usb_device *dev;
-	pasori *pp;
-	pp = (pasori *)malloc(sizeof(pasori));
+	pasori *pp = NULL;
+	(void)p;
 	usb_init();
 #ifdef DEBUG
 	usb_set_debug(255);
@@ -40,7 +41,8 @@
 		for(dev = bus->devices; dev ; dev = dev->next){
 			Log("check for %04x:%04x\n",dev->descriptor.idVendor,dev->descriptor.idProduct); /* debug */
 			if(dev->descriptor.idVendor == PASORIUSB_VENDOR &&
-			   dev->descriptor.idProduct== PASORIUSB_PRODUCT){
+			   ((dev->descriptor.idProduct== PASORIUSB_PRODUCT_RC_S310) ||
+			    (dev->descriptor.idProduct== PASORIUSB_PRODUCT_RC_S320))){
 				goto finish;
 			}
 		}
@@ -48,6 +50,7 @@
 	Log("pasori not found in USB BUS");
 	return NULL;
 finish:
+	pp = (pasori *)malloc(sizeof(pasori));
 	pp->dh = usb_open(dev);
 	pp->dev= dev;
 	
@@ -66,13 +69,13 @@
 }
 
 int pasori_send(pasori* pp,uint8* data,uint8 size,int timeout){ /* FIXME: ignore timeout */
-	uint8 msg[256];
 	uint8 resp[256];
 	signed int i;
+	(void)timeout;
 	Log("(send) send:");
 	dbg_dump(data,size);
-	i = usb_control_msg(pp->dh,USB_TYPE_VENDOR,0,0,0,data,size,400);
-	i = usb_interrupt_read(pp->dh,0x81,resp,256,400);
+	i = usb_control_msg(pp->dh,USB_TYPE_VENDOR,0,0,0,(char*)data,size,400);
+	i = usb_interrupt_read(pp->dh,0x81,(char*)resp,256,400);
 	/* printf("i = %d",i); */ /* debug */
 	if(i<0) return 1; /* FIXME:HANDLE INVALID RESPONSES */
 	if(i!=6) return 1;
@@ -88,7 +91,7 @@
 
 int pasori_recv(pasori* pp,uint8* data,uint8 size,int timeout){
 	signed int i;
-	i = usb_interrupt_read(pp->dh,0x81,data,size,timeout);
+	i = usb_interrupt_read(pp->dh,0x81,(char*)data,size,timeout);
 	if(i>0){
 		Log("(recv) recv:");
 		dbg_dump(data,i); 
