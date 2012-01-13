--- Modules/Debuggers/ProjectCenter/PTYView.m.orig	2009-01-02 18:51:00.000000000 +0100
+++ Modules/Debuggers/ProjectCenter/PTYView.m	2012-01-13 18:08:53.000000000 +0100
@@ -28,13 +28,13 @@
 #import <stdio.h> /* for stderr and perror*/
 #import <errno.h> /* for int errno */
 #import <fcntl.h>
-#import <sys/termios.h>
+#import <termios.h>
 #import <sys/types.h>
 #import <unistd.h>
 #import <stdlib.h>
 #import <string.h>
 
-#if !defined(__OpenBSD__)
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #import <stropts.h>
 #endif
 
@@ -48,7 +48,7 @@
 #define USE_FORKPTY_REPLACEMENT 1
 #endif
 
-#if !(defined (__NetBSD__)) && !(defined (__SOLARIS__)) && !(defined (__OpenBSD__))
+#if !(defined (__NetBSD__)) && !(defined (__SOLARIS__)) && !(defined (__OpenBSD__)) && !defined(__FreeBSD__)
 #  include <pty.h>
 #endif
 
