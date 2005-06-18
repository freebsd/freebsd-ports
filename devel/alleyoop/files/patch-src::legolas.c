--- src/legolas.c.orig	Sun Jan 18 16:46:00 2004
+++ src/legolas.c	Sat Jun 18 01:05:39 2005
@@ -25,7 +25,7 @@
 #include <config.h>
 #endif
 
-#include <elf.h>
+#include <libelf/libelf.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -130,7 +130,7 @@
 	case EM_RH32: return "TRW RH-32";
 	case EM_RCE: return "Motorola RCE";
 	case EM_ARM: return "ARM";
-	case EM_FAKE_ALPHA: return "Digital Alpha";
+	case EM_ALPHA: return "Digital Alpha";
 	case EM_SH: return "Hitachi SH";
 	case EM_SPARCV9: return "SPARC v9 64-bit";
 	case EM_TRICORE: return "Siemens Tricore";
