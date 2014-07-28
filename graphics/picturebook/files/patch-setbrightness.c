--- setbrightness.c.orig	Tue Dec 12 01:42:20 2000
+++ setbrightness.c	Sun Mar  9 18:20:58 2003
@@ -1,20 +1,51 @@
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
 
 #define DATA_REG 0x62
 #define CST_REG  0x66
@@ -24,28 +55,35 @@
 static void ecr_set(u16 addr, u16 value)
 {
 	while (inw(CST_REG) & 3) usleep(1);
-	outw(0x81, CST_REG);
+	outw(CST_REG, 0x81);
 	while (inw(CST_REG) & 2) usleep(1);
-	outw(addr, DATA_REG);
+	outw(DATA_REG, addr);
 	while (inw(CST_REG) & 2) usleep(1);
-	outw(value, DATA_REG);
+	outw(DATA_REG, value);
 	while (inw(CST_REG) & 2) usleep(1);
 }
 
 static u16 ecr_get(u16 addr)
 {
 	while (inw(CST_REG) & 3) usleep(1);
-	outb(0x80, CST_REG);
+	outb(CST_REG, 0x80);
 	while (inw(CST_REG) & 2) usleep(1);
-	outb(addr, DATA_REG);
+	outb(DATA_REG, addr);
 	while (inw(CST_REG) & 2) usleep(1);
 	return inw(DATA_REG);
 }
 
 int main(int argc, char *argv[])
 {
+	if(open("/dev/io", O_RDWR, 0) < 0)
+	{
+		perror("/dev/io");
+		return 1;
+	}
 	iopl(3);
 	printf("currently %x\n", ecr_get(0x96));
-	ecr_set(0x96, atoi(argv[1]));
+	if ( argv[1] != NULL ){
+		ecr_set(0x96, atoi(argv[1]));
+	}
 	return 0;
 }
