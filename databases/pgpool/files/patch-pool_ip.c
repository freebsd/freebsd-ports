--- pool_ip.c.orig	Sat Feb  3 13:22:21 2007
+++ pool_ip.c	Tue Feb 13 17:23:39 2007
@@ -184,6 +184,7 @@
 }
 
 
+#if 0
 const char *
 gai_strerror(int errcode)
 {
@@ -205,6 +206,7 @@
 
 	return hstrerror(hcode);
 }
+#endif
 
 
 /*
