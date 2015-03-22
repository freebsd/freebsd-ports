Do not depend on the crypto "package", which would not be known
to pkgconfig if base OpenSSL is used.

The shared library installed already links with -lcrypto.

	-mi

--- libzrtpcpp.pc.cmake	2013-07-01 05:10:34.000000000 -0400
+++ libzrtpcpp.pc.cmake	2015-03-06 16:19:00.000000000 -0500
@@ -9,7 +9,4 @@
 Description: GNU ZRTP core library
 Version: @VERSION@
-Requires: @CRYPTOBACKEND@
 Libs:  -L${libdir} -l@zrtplib@
 Cflags: -I${includedir}
-
-
