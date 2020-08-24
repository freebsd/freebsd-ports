--- echogui/testgui_main.c.orig	2006-02-24 20:23:37 UTC
+++ echogui/testgui_main.c
@@ -13,10 +13,10 @@ $Log$
 #include <sys/types.h>
 #include <sys/time.h>
 #include <unistd.h>
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 #include <sys/ioctl.h>
 #include <fcntl.h>
-#include <X11/forms.h>
+#include <forms.h>
 #include <string.h>
 #include <math.h>
 #include <pthread.h>
@@ -33,6 +33,7 @@ extern int atClose(FL_FORM *, void *);
 extern void dblNodeList(FL_OBJECT *, long);
 extern void getlist(FL_OBJECT *, long);
 extern int searchClose(FL_FORM *, void *);
+extern int serverInit();
 
 FILE *gpfd;
 
@@ -111,7 +112,7 @@ int main(int argc, char *argv[])
       close(controlInPipe[1]);
       close(controlInPipe[0]);
 
-      execlp("echolinux", "echolinux", 0, 0);
+      execlp("echolinux", "echolinux", 0, NULL);
       printf("We didn't execute execlp().\n");
     }
   }
