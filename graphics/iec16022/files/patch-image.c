--- image.c.orig	2017-07-05 23:29:56 UTC
+++ image.c
@@ -32,6 +32,8 @@ static inline unsigned htonl(unsigned i)
 #endif
 #include "image.h"
 
+#include <unistd.h>
+
 #define	INTERLACE
 #define CLEAR
 #define USEZLIB
