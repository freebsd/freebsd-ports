--- o/sfasli.c.orig
+++ o/sfasli.c
@@ -131,6 +131,7 @@
 extern int __remq();
 extern int __remqu();
 
+#ifndef __FreeBSD__
 #ifndef DARWIN
 #ifndef _WIN32
 int
@@ -147,6 +148,7 @@
 }
 #endif
 #endif
+#endif
 
 void
 gcl_init_sfasl() {
