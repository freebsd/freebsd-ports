--- src/sysdep1.c.orig	Sat Jun 24 18:01:29 2000
+++ src/sysdep1.c	Sun Jan 27 19:15:37 2002
@@ -71,12 +71,12 @@
 void m_setrts(fd)
 int fd;
 {
-#if defined(TIOCM_RTS) && defined(TIOCMODG)
+#if defined(TIOCM_RTS) && defined(TIOCMGET)
   int mcs=0;
 
-  ioctl(fd, TIOCMODG, &mcs);
+  ioctl(fd, TIOCMGET, &mcs);
   mcs |= TIOCM_RTS;
-  ioctl(fd, TIOCMODS, &mcs);
+  ioctl(fd, TIOCMSET, &mcs);
 #endif
 #ifdef _COHERENT
   ioctl(fd, TIOCSRTS, 0);
@@ -182,10 +182,10 @@
 int m_getdcd(fd)
 int fd;
 {
-#ifdef TIOCMODG
+#ifdef TIOCMGET
   int mcs=0;
    
-  ioctl(fd, TIOCMODG, &mcs);
+  ioctl(fd, TIOCMGET, &mcs);
   return(mcs & TIOCM_CAR ? 1 : 0);
 #else
   (void)fd;
@@ -223,8 +223,8 @@
   ioctl(fd, TIOCLGET, &lsw);
 #  endif
 #endif
-#ifdef TIOCMODG
-  ioctl(fd, TIOCMODG, &m_word);
+#ifdef TIOCMGET
+  ioctl(fd, TIOCMGET, &m_word);
 #endif
 }
 
@@ -245,8 +245,8 @@
   ioctl(fd, TIOCLSET, &lsw);
 #  endif
 #endif
-#ifdef TIOCMODS
-  ioctl(fd, TIOCMODS, &m_word);
+#ifdef TIOCMSET
+  ioctl(fd, TIOCMSET, &m_word);
 #endif
 }
 
