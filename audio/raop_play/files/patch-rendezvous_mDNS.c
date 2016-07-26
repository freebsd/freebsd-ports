--- rendezvous/mDNS.c.orig	2005-12-16 14:17:02 UTC
+++ rendezvous/mDNS.c
@@ -1139,7 +1139,7 @@ static const char *const mDNS_DomainType
 
 #include <stdio.h>
 #include <string.h>
-#include <asm/types.h>
+#include <sys/types.h>
 
 static const struct mDNSprintf_format
 {
