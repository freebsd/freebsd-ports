--- src/libpasori_com_bsdugen.c.orig	Mon Mar 20 09:12:58 2006
+++ src/libpasori_com_bsdugen.c	Fri Jan 26 23:25:58 2007
@@ -6,7 +6,17 @@
 #include <sys/ioctl.h>
 #include <errno.h>
 
+#include <sys/param.h>
+#include <string.h>
+#include <unistd.h>
+#include <err.h>
+
 #include "libpasori_liblocal.h"
+#include "libpasori.h"
+
+#define VENDOR_SONY	0x054c
+#define PRODUCT_RC_S310	0x006c
+#define PRODUCT_RC_S320	0x01bb
 
 void dbg_dump(uint8* d,int size){
         int i;
@@ -16,25 +26,88 @@
         Log("\n");
 }
 
-pasori* pasori_open(char* c){ /* FIXME:unused arg. */
+void search_pasori(char* devname, int devnamelen){
+    int pathnum;
+    char buspath[16];
+    int busfd;
+
+    memset(devname, 0, devnamelen);
+    for (pathnum = 0; pathnum < 10; pathnum++) {
+	snprintf(buspath, sizeof(buspath), "/dev/usb%d", pathnum);
+	if ((busfd = open(buspath, O_RDONLY)) >= 0) {
+	    int devnum;
+	    for (devnum = 1; devnum < USB_MAX_DEVICES; devnum++) {
+		struct usb_device_info di;
+		di.udi_addr = devnum;
+		if (ioctl(busfd, USB_DEVICEINFO, &di) != -1) {
+		    if ((di.udi_vendorNo == VENDOR_SONY) &&
+			((di.udi_productNo == PRODUCT_RC_S310) ||
+			 (di.udi_productNo == PRODUCT_RC_S320))) {
+
+			int i;
+			for (i=0; i<USB_MAX_DEVNAMES; i++) {
+			    if (strncmp(di.udi_devnames[i], "ugen", 4) == 0) {
+				snprintf(devname, devnamelen,
+					 "/dev/%s", di.udi_devnames[i]);
+				devname[devnamelen -1] = '\0';
+				break;
+			    }
+			}
+		    }
+		}
+		if (devname[0] != '\0') break;
+	    }
+	    close(busfd);
+	    if (devname[0] != '\0') break;
+	} else {
+	    continue;
+	}
+    }
+}    
+
+pasori* pasori_open(char* c){
         int config;
         pasori *pp;
-        char* pasori_devname;
-        char* pasori_intr;
+	char pasori_devname[USB_MAX_DEVNAMELEN +1];
+        char pasori_ctrl[PATH_MAX];
+        char pasori_intr[PATH_MAX];
         int i;
-	int t;
-        const int timeout = 400;
-        const int size = 0;
         pp = (pasori *)malloc(sizeof(pasori));
 
-        pasori_devname = "/dev/ugen0.00"; /* FIXME:hardcoded device path */
-        pasori_intr = "/dev/ugen0.01";
-
-        pp->fd_cntl = open(pasori_devname,O_RDWR);
+	if (c != NULL) {
+		snprintf(pasori_devname, sizeof(pasori_devname), 
+			 "%s", c);
+		pasori_devname[sizeof(pasori_devname) -1] = '\0';
+	} else {
+		search_pasori(pasori_devname, sizeof(pasori_devname));
+		if (strlen(pasori_devname) == 0) {
+		    warnx("No PaSoRi was found.");
+		    return NULL;
+		}
+	}
+#if defined(__NetBSD__) || defined(__OpenBSD__)
+	snprintf(pasori_ctrl, sizeof(pasori_ctrl), 
+		 "%s.00", pasori_devname);
+#else
+	snprintf(pasori_ctrl, sizeof(pasori_ctrl), 
+		 "%s", pasori_devname);
+#endif
+	pasori_ctrl[sizeof(pasori_ctrl) -1] = '\0';
+	snprintf(pasori_intr, sizeof(pasori_intr), 
+		 "%s.1", pasori_devname);
+	pasori_intr[sizeof(pasori_intr) -1] = '\0';
+
+        pp->fd_cntl = open(pasori_ctrl,O_RDWR);
+	if (pp->fd_cntl == -1) {
+	    warn("%s", pasori_ctrl);
+	}
 
         config = 1;
         i = ioctl(pp->fd_cntl,USB_SET_CONFIG,&config);
         pp->fd_intr = open(pasori_intr,O_RDONLY | O_NONBLOCK);
+	if (pp->fd_intr == -1) {
+	    warn("%s", pasori_intr);
+	}
         if( (pp->fd_cntl < 0) || (pp->fd_intr < 0) ){
                 Log("error opening pasori.%d %d",pp->fd_cntl,pp->fd_intr);
                 close(pp->fd_cntl);
@@ -47,7 +120,6 @@
 
 int pasori_send(pasori* pp,uint8 *cmd,uint8 size,int timeout){
         struct usb_ctl_request req;
-        uint8 msg[128]; /* FIXME:max message bytes? */
         uint8 resp[256];
         signed int i;
 	int t;
@@ -90,11 +162,12 @@
 int pasori_recv(pasori* pp,uint8* buf,uint8 bufsize,int timeout){
         signed int i;
         int state;
-        int size;
+        int size=0;
         int ptr;
-        int one = 1;
 	fd_set fds;
 	struct timeval tv;
+
+	(void)bufsize; /* FIXME: buffer size is not checked */
 	
         uint8 resp;
         state = STATE_UNKNOWN;
@@ -156,5 +229,7 @@
 void pasori_close(pasori* p){
         close(p->fd_intr);
         close(p->fd_cntl);
+	free(p);
+	p = NULL;
 }
 
