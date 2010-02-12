--- src/CASCatch/CASCatch_CatchSignals.cxx.orig	2009-08-04 15:45:29.000000000 +0700
+++ src/CASCatch/CASCatch_CatchSignals.cxx	2009-08-04 15:49:47.000000000 +0700
@@ -56,7 +56,7 @@
 #include <OSD_SIGBUS.hxx>
 #include <OSD_SIGSEGV.hxx>
 #include <OSD_SIGSYS.hxx>
-#ifndef LIN
+#if !defined LIN && !defined FREEBSD
 #include <exception.h>
 #endif
 
@@ -81,7 +81,7 @@
 #include <signal.h>
 #include <sys/signal.h>
 
-#ifdef LIN
+#if defined LIN || defined FREEBSD
 # include <stdlib.h>
 # include <stdio.h>
 #else
