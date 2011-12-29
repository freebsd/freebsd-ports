--- src/sysdep1.c.orig	2009-12-12 16:47:47.000000000 +0100
+++ src/sysdep1.c	2011-12-28 16:07:59.000000000 +0100
@@ -65,13 +65,13 @@ static void m_setrts(int fd)
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
 }
@@ -180,11 +180,11 @@ int m_getdcd(int fd)
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
@@ -227,8 +227,8 @@ void m_savestate(int fd)
   ioctl(fd, TIOCLGET, &lsw);
 #  endif
 #endif
-#ifdef TIOCMODG
-  ioctl(fd, TIOCMODG, &m_word);
+#ifdef TIOCMGET
+  ioctl(fd, TIOCMGET, &m_word);
 #endif
 }
 
@@ -252,8 +252,8 @@ void m_restorestate(int fd)
   ioctl(fd, TIOCLSET, &lsw);
 #  endif
 #endif
-#ifdef TIOCMODS
-  ioctl(fd, TIOCMODS, &m_word);
+#ifdef TIOCMSET
+  ioctl(fd, TIOCMSET, &m_word);
 #endif
 }
 
