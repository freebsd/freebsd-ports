--- parser/sdp.c.orig	Sat Sep 13 01:38:11 2003
+++ parser/sdp.c	Tue Dec 14 21:59:15 2004
@@ -31,6 +31,7 @@
 
 #include <sys/types.h>
 #include <netinet/in.h>
+#include <inttypes.h>
 #include <stdio.h>
 
 #include "parser.h"
@@ -203,7 +204,7 @@
 		break;
 	case 16:/* 128-bit */
 		get_u128(frm, &val, &val2);
-		printf(" 0x%llx 0x%llx", val2, val);
+		printf(" 0x%" PRIx64 "0x%" PRIx64, val2, val);
 		return;
 	default: /* syntax error */
 		printf(" err");
@@ -212,7 +213,7 @@
 		return;
 	}
 
-	printf(" 0x%llx", val);
+	printf(" 0x%" PRIx64, val);
 }
 
 static void print_uuid(int n, struct frame *frm)
