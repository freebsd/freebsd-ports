--- libs/m3core/src/unix/freebsd-4.i386/Unix.i3.bak	2002-03-23 05:28:45.000000000 +0300
+++ libs/m3core/src/unix/freebsd-4.i386/Unix.i3	2014-05-02 09:33:09.000000000 +0400
@@ -149,6 +149,7 @@
     l_pid:    pid_t := 0;
     l_type:   short; (* see below *)
     l_whence: short;
+    l_sysid:  int   := 0;
   END;
 (* ok *)
 
