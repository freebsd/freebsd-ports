Index: paranoia/cdda_paranoia.h
===================================================================
RCS file: /home/cvs/cdparanoia/paranoia/cdda_paranoia.h,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -r1.1.1.1 -r1.2
--- paranoia/cdda_paranoia.h	2003/01/05 09:46:26	1.1.1.1
+++ paranoia/cdda_paranoia.h	2003/01/05 12:55:20	1.2
@@ -34,6 +34,8 @@
 #define PARANOIA_MODE_NEVERSKIP   32
 
 #ifndef CDP_COMPILE
+#include <cdda_interface.h>
+
 typedef void cdrom_paranoia;
 #endif
 
