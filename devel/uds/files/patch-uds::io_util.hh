--- uds/io_util.hh.orig	Thu Sep  5 10:14:44 2002
+++ uds/io_util.hh	Thu Sep  5 10:21:14 2002
@@ -27,8 +27,7 @@
 
 #include <uds/fdstream.hh>
 #include <uds/stdexcpt.hh>
-#include <byteswap.h>
-#include <endian.h>
+#include <sys/endian.h>
 #include <limits>
 #include <unistd.h>
 
@@ -45,33 +44,10 @@
 	end_little = 1234,		///< little-endian
 	end_big = 4321,			///< big-endian
 	end_net = end_big,		///< network byte order
-	end_host = __BYTE_ORDER	///< host byte order
+	end_host = BYTE_ORDER	///< host byte order
 };
 
 typedef unsigned endianess_t;
-
-
-// the following bswap* functions need to be defined since
-// gcc (at least 2.95.3) aborts with an error if the bswap_* macros are
-// used inside of a template function and expand to assembly code.
-
-inline u_int16_t
-bswap16( u_int16_t x )
-{
-	return bswap_16( x );
-}
-
-inline u_int32_t
-bswap32( u_int32_t x )
-{
-	return bswap_32( x );
-}
-
-inline u_int64_t
-bswap64( u_int64_t x )
-{
-	return bswap_64( x );
-}
 
 
 /** changes the endianess of an integral type
