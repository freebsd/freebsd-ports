--- faxd/GettySysV.c++.orig	2009-12-28 20:05:40.000000000 +0100
+++ faxd/GettySysV.c++	2010-01-26 22:44:19.000000000 +0100
@@ -49,8 +49,12 @@
 #define ut_time       ut_tv.tv_sec
 #endif
 #else
+#ifdef __FreeBSD__
+#define ut_time       ut_tv.tv_sec
+#else
 #define ut_time       ut_xtime
 #endif
+#endif
 
 #define getutent      getutxent
 #define getutid       getutxid
@@ -172,6 +176,7 @@
 void
 SysVGetty::writeWtmp(utmp* ut)
 {
+#if !defined(__FreeBSD__)
     // append record of login to wtmp file
 #if HAS_UTMPX
     updwtmpx(_PATH_WTMPX, ut);
@@ -182,6 +187,7 @@
 	Sys::close(fd);
     }
 #endif
+#endif
 }
 
 /*
