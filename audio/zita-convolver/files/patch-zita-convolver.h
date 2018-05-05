--- zita-convolver.h.orig	2018-04-28 15:44:28 UTC
+++ zita-convolver.h
@@ -42,7 +42,7 @@ extern int zita_convolver_minor_version 
 #endif
 
 
-#if defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__GNU__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__GNU__)
 
 // NOTE: __FreeBSD_kernel__  and __GNU__ were added by the Debian maintainers
 // (the latter for the HURD version of Debian). Things are reported to work
