--- System/Applications/Terminal/TerminalView.m.orig	2010-05-23 11:43:45.000000000 +0000
+++ System/Applications/Terminal/TerminalView.m
@@ -21,7 +21,7 @@ stupid but fast character cell display v
 #  include <termios.h>
 #  include <pcap.h>
 #else
-#ifdef freebsd
+#if defined(freebsd) || defined(__DragonFly__)
 #  include <sys/types.h>
 #  include <sys/ioctl.h>
 #  include <termios.h>
@@ -37,9 +37,11 @@ stupid but fast character cell display v
 #include <unistd.h>
 #include <fcntl.h>
 #ifndef freebsd
+# ifndef __DragonFly__
 #ifndef __NetBSD__
 #  include <pty.h>
 #endif
+# endif
 #endif
 
 #include <Foundation/NSBundle.h>
