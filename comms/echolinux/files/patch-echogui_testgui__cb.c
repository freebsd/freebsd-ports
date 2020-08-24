--- echogui/testgui_cb.c.orig	2006-02-24 19:28:15 UTC
+++ echogui/testgui_cb.c
@@ -8,13 +8,16 @@ $Log$
 
 ****************************/ 
 
+#include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 #include <sys/wait.h>
+#include <sys/time.h>
 #include <sys/types.h>
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 #include <sys/ioctl.h>
 #include <fcntl.h>
-#include <X11/forms.h>
+#include <forms.h>
 #include <math.h>
 #include <signal.h>
 #include <pthread.h>
@@ -429,6 +432,7 @@ int searchClose(FL_FORM *form, void *data){
 
   // puts("In searchclose()");
   fl_hide_form(fd_searchForm->searchForm);
+  return (0);
 }
 
 /**********************/
