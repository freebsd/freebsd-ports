--- unixport/rsym_elf.c.orig	Sat May 13 19:40:14 2000
+++ unixport/rsym_elf.c	Mon Dec  3 22:49:54 2001
@@ -11,8 +11,9 @@
 */
 
 #include "string.h"
-#ifdef __linux__
+#if defined(__linux__) || defined(__ELF__)
 /* Needed these to get it working with Linux.  Bill Metzenthen 23 May 95 */
+/* Also with FreeBSD 4.3. Tim Pierce, 1 December 2001 */
 #define IN_RSYM 1
 #include <stdio.h>
 
