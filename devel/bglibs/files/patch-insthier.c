--- insthier.c.orig	Tue Jun  3 19:20:34 2003
+++ insthier.c	Tue Jun  3 19:21:30 2003
@@ -15,7 +15,7 @@
 
   bin = d(home, "bin", -1, -1, 0755);
 
-  inc = d(home, "include", -1, -1, 0755);
+  inc = d(home, "include/bglibs", -1, -1, 0755);
 
   cf(inc, "installer.h", -1, -1, 0644, "install/installer.h");
   C(inc, sysdeps.h);
