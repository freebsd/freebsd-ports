$FreeBSD$

--- jdk/src/solaris/native/java/net/NetworkInterface.c	Mon Jun 27 22:08:16 2011 -0700
+++ jdk/src/solaris/native/java/net/NetworkInterface.c	Thu Jul 07 23:37:05 2011 -0700
@@ -1968,7 +1968,11 @@
       return -1;
   }
 
-  return if2.ifr_flags;
+#ifdef __FreeBSD__
+  return ((if2.ifr_flags & 0xffff) | (if2.ifr_flagshigh << 16));
+#else
+  return (((int) if2.ifr_flags) & 0xffff);
+#endif
 }
 
 #endif
