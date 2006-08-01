--- src/uparport.hh	Sat Jun 24 13:19:29 2006
+++ src/uparport.hh	Sat Jun 24 13:20:31 2006
@@ -15,10 +15,10 @@
 extern "C"
 {
 #include <sys/ioctl.h> 
-// in RedHat & Mandrake distro, ppdev.h is into /usr/include/linux 
-#include <linux/ppdev.h>   
 #include <sys/time.h>
-// #include <sys/io.h> 
+#include <machine/cpufunc.h>
+#include <dev/ppbus/ppi.h>
+#include <dev/ppbus/ppbconf.h>
 #include <fcntl.h>
 }           
 
