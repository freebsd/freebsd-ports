--- FreeBSD/vpb.c	Mon May  3 13:49:58 2004
+++ FreeBSD/vpb.c	Mon Mar 14 10:47:29 2005
@@ -52,8 +52,6 @@
 #define BLOCK_DELAY  1       /* delay (us) between adjacent blocks           */
 #define SIZE_LCR     128     /* size of 9050 local config reg space in bytes */
 
-#define MIN(a,b) (((a) < (b)) ? (a) : (b))
-
 #define EEPROM_SIZE  64
 #define EEPROM_CS    25		/* Chip select bit */
 #define EEPROM_CLK   24
@@ -68,16 +66,20 @@
 
 #include <sys/types.h>
 #include <sys/module.h>
-#include <sys/systm.h>  /* uprintf                               */
+#include <sys/systm.h>		/* uprintf                               */
 #include <sys/errno.h>
-#include <sys/param.h>  /* defines used in kernel.h              */
-#include <sys/kernel.h> /* types used in module initialization   */
-#include <sys/conf.h>   /* cdevsw struct                         */
-#include <sys/uio.h>    /* uio struct                            */
+#include <sys/param.h>		/* defines used in kernel.h              */
+#include <sys/kernel.h>		/* types used in module initialization   */
+#include <sys/conf.h>		/* cdevsw struct                         */
+#include <sys/uio.h>		/* uio struct                            */
 #include <sys/malloc.h>
-#include <sys/bus.h>    /* structs, prototypes for pci bus stuff */
-#include <pci/pcivar.h> /* For get_pci macros!                   */
-#include <sys/vpbio.h>	/* IOCTL definitions                     */
+#include <sys/bus.h>    	/* structs, prototypes for pci bus stuff */
+#if __FreeBSD_version > 500000
+#include <dev/pci/pcivar.h>	/* For get_pci macros!                   */
+#else
+#include <pci/pcivar.h>		/* For get_pci macros!                   */
+#endif
+#include "vpbio.h"		/* IOCTL definitions                     */
 #include <machine/clock.h>	
 #include <vm/vm.h>	
 #include <vm/pmap.h>	
@@ -113,26 +115,34 @@
 \*---------------------------------------------------------------------------*/
 
 /* Character device entry points */
-
+#if __FreeBSD_version > 500000
+#if __FreeBSD_version > 503000
+#define DEV_T		struct cdev*
+#else
+#define DEV_T		dev_t
+#endif
+#define D_THREAD_T	thread
+#define CDEV_MAJOR MAJOR_AUTO	/* reserved for local use */
+#else
+#define DEV_T		dev_t
+#define D_THREAD_T	proc
+#define CDEV_MAJOR 33		/* reserved for lkms */
+#endif
 static struct cdevsw vpb_cdevsw = {
-  vpb_open,
-  vpb_close,
-  vpb_read,
-  vpb_write,
-  vpb_ioctl,
-  nopoll,
-  nommap,
-  nostrategy,
-  "vpb",
-  201,                   /* reserved for local use */
-  nodump,
-  nopsize,
-  D_TTY,
-  -1
+#if __FreeBSD_version > 503000
+	.d_version =	D_VERSION,
+#endif
+        .d_open =       vpb_open,
+        .d_close =      vpb_close,
+        .d_read =       vpb_read,
+        .d_write =      vpb_write,
+        .d_ioctl =      vpb_ioctl,
+        .d_name =       "vpb",
+        .d_maj =        CDEV_MAJOR,
 };
 
 /* number of valid PCI devices detected */
-static int numPCI; 
+static int numPCI=0; 
 
 /* translated base address of PLX9050 regions */
 static unsigned char  *base0[MAX_V4PCI];
@@ -144,7 +154,7 @@
 static short buf[SIZE_WD];
 
 /* vars */
-static dev_t sdev;
+static DEV_T sdev[MAX_V4PCI] ={ 0 }; /* replace with dynamic allocation! */
 
 static device_method_t vpb_methods[] = {
   /* Device interface */
@@ -154,15 +164,19 @@
   DEVMETHOD(device_shutdown,  vpb_shutdown),
   DEVMETHOD(device_suspend,   vpb_suspend),
   DEVMETHOD(device_resume,    vpb_resume),
-
   { 0, 0 }
 };
 
+struct vpb_softc {
+   u_int32_t unit;
+   DEV_T dev;
+};
+
 static driver_t vpb_driver = {
   "vpb",
   vpb_methods,
   0,
-  /*  sizeof(struct vpb_softc), */
+  /* sizeof(struct vpb_softc), */
 };
 
 static devclass_t vpb_devclass;
@@ -173,7 +187,7 @@
        open/close/read/write at this point */
 
 static int
-vpb_open(dev_t dev, int oflags, int devtype, struct proc *p)
+vpb_open(DEV_T dev, int oflags, int devtype, struct D_THREAD_T *td)
 {
   int err = 0;
 
@@ -181,7 +195,7 @@
 }
 
 static int
-vpb_close(dev_t dev, int fflag, int devtype, struct proc *p)
+vpb_close(DEV_T dev, int fflag, int devtype, struct D_THREAD_T *td)
 {
   int err=0;
 
@@ -189,7 +203,7 @@
 }
 
 static int
-vpb_read(dev_t dev, struct uio *uio, int ioflag)
+vpb_read(DEV_T dev, struct uio *uio, int ioflag)
 {
   int err = 0;
 
@@ -197,7 +211,7 @@
 }
 
 static int
-vpb_write(dev_t dev, struct uio *uio, int ioflag)
+vpb_write(DEV_T dev, struct uio *uio, int ioflag)
 {
   int err = 0;
 
@@ -205,7 +219,7 @@
 }
 
 static int
-vpb_ioctl(dev_t dev, u_long cmd, caddr_t arg, int flag, struct proc *pr)
+vpb_ioctl(DEV_T dev, u_long cmd, caddr_t arg, int flag, struct D_THREAD_T *td)
 {	
   VPB_DATA *vpb_data;  /* ioctl parameters from user space */
   short    *data;      /* user space address of data       */
@@ -318,8 +332,14 @@
   int         subsystem;
   char        *s; 
 
+  if(numPCI >= MAX_V4PCI) {
+    return ENXIO;
+  }
+
+  /* struct vpb_softc *sc = (struct vpb_softc *)device_get_softc(dev); */
   if ((pci_get_vendor(dev) == 0x10b5) && (pci_get_device(dev) == 0x9050)) {
 
+    /* bzero(sc, sizeof(struct vpb_softc)); */
     /* check that subsytem ID & Subsytem Vendor matches */
     subsystem = pci_read_config(dev, 0x2c, 4);
     s = (char*)&subsystem;
@@ -327,7 +347,7 @@
     if ((s[3] == 'V') && (s[2] == '4') && (s[1] == 'V') && (s[0] == 'T')) {
       
       printf("V4PCI %d found!\n", numPCI);
-      device_set_desc(dev, "Voicetronix V4PCI Computer Telephony Card");
+      device_set_desc_copy(dev, "Voicetronix V4PCI Computer Telephony Card");
       return 0;
     }
   }
@@ -341,13 +361,16 @@
 vpb_attach(device_t dev)
 {
   vm_offset_t paddr;
+  /* int         unit; */
 
-  sdev = make_dev(&vpb_cdevsw,
+  /* unit = device_get_unit(dev); */
+  sdev[numPCI] = make_dev(&vpb_cdevsw,
 		  0,
 		  UID_ROOT,
 		  GID_WHEEL,
 		  0600,
-		  "vpb");
+		  "vpb%d",
+		  numPCI);
 
   /* OK, V4PCI found, so map address regions..... */
   paddr = (vm_offset_t)pci_read_config(dev, PCI_BASE_ADDR0, 4) & ~0xf;
@@ -357,7 +380,9 @@
   base2[numPCI] = pmap_mapdev(paddr, sizeof(short)*SIZE_WD);
 
   /* set wait-states */
-  *(base0[0]+0x28) = 0x00440422;     
+  /* ((unsigned int)*(base0[0]+0x28)) = 0x00440422; */
+  /* now adding 1 wait-state to Write cycle hold */
+  ((unsigned int)*(base0[0]+0x28)) = 0x070440422;     
 
   numPCI++;
 
@@ -369,6 +394,11 @@
 static int
 vpb_detach(device_t dev)
 {
+  if(numPCI>0 && sdev[numPCI-1]!=NULL) {
+    destroy_dev(sdev[numPCI-1]);
+    sdev[numPCI-1]=NULL;
+    numPCI--;
+  }
   return 0;
 }
 
@@ -491,4 +521,4 @@
         cntrl &= 1;
         return(cntrl);
 }
-                               
+
