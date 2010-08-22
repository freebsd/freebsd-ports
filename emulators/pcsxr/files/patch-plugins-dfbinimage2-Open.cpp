--- plugins/dfbinimage2/Open.cpp.orig	2010-04-20 06:08:48.510837620 +0000
+++ plugins/dfbinimage2/Open.cpp	2010-04-20 06:09:12.454669867 +0000
@@ -150,7 +150,7 @@
    return theCD->stopTrack();
 }
 
-#if defined _WINDOWS || defined __CYGWIN32__
+#if defined _WINDOWS || defined __CYGWIN32__ || defined __FreeBSD__
 
 long CALLBACK CDRgetStatus(struct CdrStat *stat) 
 {
