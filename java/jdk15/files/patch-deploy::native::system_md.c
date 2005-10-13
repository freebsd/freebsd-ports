$FreeBSD$

--- ../../deploy/src/javaws/solaris/native/system_md.c	19 May 2005 19:38:24 -0000	1.4
+++ ../../deploy/src/javaws/solaris/native/system_md.c	5 Oct 2005 17:59:39 -0000
@@ -10,7 +10,7 @@
  * unicode conversion for now at all.  It means that japanese, korean,
  * chinese, etc locales are not available.
  */
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
 #define DISABLE_LOCALE 1
 #endif
 
