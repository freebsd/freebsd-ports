--- ./o/unixfasl.c.orig	Sat Feb 15 00:38:28 2003
+++ ./o/unixfasl.c	Sat Sep 13 23:52:25 2003
@@ -282,7 +282,7 @@
 static int
 faslink(object faslfile, object ldargstring)
 {
-#if defined(__linux__) && defined(__ELF__)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(__ELF__)
   FEerror("faslink() not supported for ELF yet",0);
   return 0;
 #else
