--- Makefile.inc.orig	Wed Jan 21 10:56:37 2004
+++ Makefile.inc	Wed Jan 21 10:56:47 2004
@@ -27,7 +27,7 @@
 # C options
 #
 CFLAGS+= -g -I${.CURDIR}/../lib
-CFLAGS+= -Wall -Wwrite-strings -Wstrict-prototypes -Wmissing-prototypes -Werror
+CFLAGS+= -Wall -Wwrite-strings -Wstrict-prototypes -Wmissing-prototypes
 CFLAGS+= -DDEFAULT_PORT=\"${GPS_SERIAL_PORT}\" ${VERSION} ${SIO_TYPE}
 
 # Figure out where the library lives for proper dependencies
