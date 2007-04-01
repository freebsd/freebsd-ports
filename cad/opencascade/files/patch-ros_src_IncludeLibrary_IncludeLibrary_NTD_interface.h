--- ros/src/IncludeLibrary/IncludeLibrary_NTD_interface.h.orig	Mon Oct 29 18:01:42 2001
+++ ros/src/IncludeLibrary/IncludeLibrary_NTD_interface.h	Thu Aug 10 21:46:28 2006
@@ -352,7 +352,7 @@
                                    int k_synch ,
                                    PREAD_AST_MBX func,
                                    PSTATUS sts);
-#if !defined(__hpux) && !defined(HPUX) && !defined(__osf__) && !defined(DECOSF1) && !defined(WNT) && !defined(LIN) && !defined(linux) && !defined(AIX) && !defined(_AIX)
+#if !defined(__hpux) && !defined(HPUX) && !defined(__osf__) && !defined(DECOSF1) && !defined(WNT) && !defined(LIN) && !defined(linux) && !defined(AIX) && !defined(_AIX) && !defined(__FreeBSD__)
 extern
 #ifdef CSF1
        "C" {
