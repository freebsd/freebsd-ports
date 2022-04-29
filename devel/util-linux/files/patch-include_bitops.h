commit a38d1f69fee5ca7e883b09ed3668a7da3b161051
Author: Warner Losh <imp@FreeBSD.org>
Date:   Fri Apr 29 15:29:44 2022 -0600

    BSD: Use byteswap.h and endian.h defined macos when present
    
    Newer versions of FreeBSD will have a glibc compatible
    byteswap.h. Currently, this file assumes that FreeBSD requires
    bswap{16,32,64} to always be defined. This isn't the case when we're
    using the byteswap.h file (which is enabled by HAVE_BYTESWAP_H
    define). Assume that if byteswap.h and endian.h are present, then the
    proper macros are defined.  Otherwise, assume that sys/endian.h is
    present and paper over the small differences between the BSDs for this
    file.
    
    Signed-off-by: Warner Losh <imp@bsdimp.com>

--- include/bitops.h
+++ include/bitops.h
@@ -20,6 +20,12 @@
 #  include <sys/endian.h>
 #endif
 
+#if !(defined(HAVE_BYTESWAP_H) && defined(HAVE_ENDIAN_H))
+/*
+ * When both byteswap.h and endian.h are preseent, the proper macros are defined
+ * as those files are glibc compatible.  Otherwise, compensate for the slightly
+ * different interfaces between the different BSDs.
+ */
 #if defined(__OpenBSD__)
 # include <sys/types.h>
 # define be16toh(x) betoh16(x)
@@ -47,6 +53,7 @@
 # define bswap_32(x) OSSwapInt32(x)
 # define bswap_64(x) OSSwapInt64(x)
 #endif
+#endif
 
 /*
  * Fallbacks
