--- src/sysdep1.c.orig	Wed Jul 23 04:06:53 2003
+++ src/sysdep1.c	Wed Jul 23 04:10:29 2003
@@ -82,13 +82,13 @@
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
@@ -215,11 +215,11 @@
     return portfd_is_connected;
   }
 #endif
-#ifdef TIOCMODG
+#ifdef TIOCMGET
   {
     int mcs=0;
      
-    ioctl(fd, TIOCMODG, &mcs);
+    ioctl(fd, TIOCMGET, &mcs);
     return(mcs & TIOCM_CAR ? 1 : 0);
   }
 #else
@@ -262,8 +262,8 @@
   ioctl(fd, TIOCLGET, &lsw);
 #  endif
 #endif
-#ifdef TIOCMODG
-  ioctl(fd, TIOCMODG, &m_word);
+#ifdef TIOCMGET
+  ioctl(fd, TIOCMGET, &m_word);
 #endif
 }
 
@@ -288,8 +288,8 @@
   ioctl(fd, TIOCLSET, &lsw);
 #  endif
 #endif
-#ifdef TIOCMODS
-  ioctl(fd, TIOCMODS, &m_word);
+#ifdef TIOCMSET
+  ioctl(fd, TIOCMSET, &m_word);
 #endif
 }
 
