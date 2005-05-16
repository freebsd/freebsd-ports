--- support/mph.h.orig	Tue Apr  5 10:43:05 2005
+++ support/mph.h	Thu May  5 17:34:31 2005
@@ -149,6 +149,8 @@
 
 #endif /* ndef INC_mph_H */
 
+int ttyname_r (int fd, char *buf, size_t buflen);
+
 /*
  * vim: noexpandtab
  */
