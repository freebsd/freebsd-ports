--- vaiobat.c.orig	Thu Feb  8 09:15:07 2001
+++ vaiobat.c	Sun Mar  9 18:22:57 2003
@@ -1,21 +1,54 @@
 #define _XOPEN_SOURCE 500
+#define __BSD_VISIBLE 1
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
+#ifdef LINUX
 #include <sys/io.h>
+#endif
 #include <sys/mman.h>
 #include <dirent.h>
 #include <ctype.h>
+#ifdef LINUX
 #include <malloc.h>
+#endif 
 #include <string.h>
 #include <signal.h>
+#ifdef HAVE_GETOPT_H
 #include <getopt.h>
+#endif
+#ifdef LINUX
 #include <linux/pci.h>
+#endif
 #include <sys/time.h>
 
 
+
+#ifdef __FreeBSD__
+#include <machine/cpufunc.h>
+static int deviofd=-1;
+static int iopl(int lvl)
+{
+  if(lvl==0){
+    if(deviofd!=-1){
+      close(deviofd);
+      deviofd=-1;
+    }    
+    return 0;
+  }else if(lvl==3){
+    if(deviofd==-1){
+      deviofd=open("/dev/io",0);
+    }
+    return deviofd;
+  }
+  return -1;
+}
+
+#endif
+
+
 #define DATA_REG 0x62
 #define CST_REG  0x66
 
@@ -25,20 +58,20 @@
 static void ecr_set(u8 addr, u8 value)
 {
 	while (inb(CST_REG) & 3) usleep(1);
-	outb(0x81, CST_REG);
+	outb(CST_REG, 0x81);
 	while (inb(CST_REG) & 2) usleep(1);
-	outb(addr, DATA_REG);
+	outb(DATA_REG, addr);
 	while (inb(CST_REG) & 2) usleep(1);
-	outb(value, DATA_REG);
+	outb(DATA_REG, value);
 	while (inb(CST_REG) & 2) usleep(1);
 }
 
 static u8 ecr_get(u8 addr)
 {
 	while (inb(CST_REG) & 3) usleep(1);
-	outb(0x80, CST_REG);
+	outb(CST_REG, 0x80);
 	while (inb(CST_REG) & 2) usleep(1);
-	outb(addr, DATA_REG);
+	outb(DATA_REG, addr);
 	while (inb(CST_REG) & 2) usleep(1);
 	return inb(DATA_REG);
 }
