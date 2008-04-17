--- src/sysdep1.c.orig	2007-10-10 22:18:20.000000000 +0200
+++ src/sysdep1.c	2008-04-17 19:48:58.000000000 +0200
@@ -84,13 +84,13 @@
   if (portfd_is_socket)
     return;
 #endif
-#if defined(TIOCM_RTS) && defined(TIOCMODG)
+#if defined(TIOCM_RTS) && defined(TIOCMGET)
   {
     int mcs=0;
 
-    ioctl(fd, TIOCMODG, &mcs);
+    ioctl(fd, TIOCMGET, &mcs);
     mcs |= TIOCM_RTS;
-    ioctl(fd, TIOCMODS, &mcs);
+    ioctl(fd, TIOCMSET, &mcs);
   }
 #endif
 #ifdef _COHERENT
@@ -213,11 +213,11 @@
     return portfd_is_connected;
   }
 #endif
-#ifdef TIOCMODG
+#ifdef TIOCMODGET
   {
     int mcs = 0;
 
-    if (ioctl(fd, TIOCMODG, &mcs) < 0)
+    if (ioctl(fd, TIOCMODGET, &mcs) < 0)
       return -1;
     return mcs & TIOCM_CAR ? 1 : 0;
   }
@@ -260,8 +260,8 @@
   ioctl(fd, TIOCLGET, &lsw);
 #  endif
 #endif
-#ifdef TIOCMODG
-  ioctl(fd, TIOCMODG, &m_word);
+#ifdef TIOCMGET
+  ioctl(fd, TIOCMGET, &m_word);
 #endif
 }
 
@@ -285,8 +285,8 @@
   ioctl(fd, TIOCLSET, &lsw);
 #  endif
 #endif
-#ifdef TIOCMODS
-  ioctl(fd, TIOCMODS, &m_word);
+#ifdef TIOCMSET
+  ioctl(fd, TIOCMSET, &m_word);
 #endif
 }
 
