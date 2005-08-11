
$FreeBSD$

--- compiler.h	2003/02/16 00:04:39	1.1
+++ compiler.h	2003/02/16 00:05:09
@@ -60,7 +60,7 @@
 
 // Additional type definition
 
-#if !(defined(_ILP32) || defined(_LP64) || defined(_STDINT_H) || defined(_SYS_INTTYPES_H_) /* for FreeBSD */)
+#if !(defined(_ILP32) || defined(_LP64) || defined(__FreeBSD__))
 #  ifndef _UINT16_T
 #    define _UINT16_T
 typedef unsigned short uint16_t;
@@ -196,7 +196,7 @@
 #    include <linux/version.h>	// for kernel version
 #  elif defined(__FreeBSD__) || defined(__NetBSD__)
 #    ifdef __FreeBSD__
-#      if __FreeBSD__ >= 4 && JDK_VER < 12
+#      if __FreeBSD__ == 4 && JDK_VER < 12
 	// In this case, the 3rd arg. of sig. handler is not (sigcontext *).
 #	 define SIGCONTEXT_T struct osigcontext
 #      else
