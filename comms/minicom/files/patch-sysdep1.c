--- sysdep1.c.orig	Wed Mar 15 08:45:03 2000
+++ sysdep1.c	Fri Nov 10 09:26:24 2000
@@ -69 +69 @@
-#if defined(TIOCM_RTS) && defined(TIOCMODG)
+#if defined(TIOCM_RTS) && defined(TIOCMGET)
@@ -72 +72 @@
-  ioctl(fd, TIOCMODG, &mcs);
+  ioctl(fd, TIOCMGET, &mcs);
@@ -74 +74 @@
-  ioctl(fd, TIOCMODS, &mcs);
+  ioctl(fd, TIOCMSET, &mcs);
@@ -180 +180 @@
-#ifdef TIOCMODG
+#ifdef TIOCMGET
@@ -183 +183 @@
-  ioctl(fd, TIOCMODG, &mcs);
+  ioctl(fd, TIOCMGET, &mcs);
@@ -221,2 +221,2 @@
-#ifdef TIOCMODG
-  ioctl(fd, TIOCMODG, &m_word);
+#ifdef TIOCMGET
+  ioctl(fd, TIOCMGET, &m_word);
@@ -243,2 +243,2 @@
-#ifdef TIOCMODS
-  ioctl(fd, TIOCMODS, &m_word);
+#ifdef TIOCMSET
+  ioctl(fd, TIOCMSET, &m_word);
