$FreeBSD$

--- ../../j2se/src/share/native/java/util/zip/zlib-1.1.3/zconf.h	8 Nov 2004 22:27:36 -0000	1.1.1.1
+++ ../../j2se/src/share/native/java/util/zip/zlib-1.1.3/zconf.h	20 Oct 2005 18:19:49 -0000
@@ -11,44 +11,49 @@
 /* for _LP64 */
 #include <sys/types.h>
 
+/**
+ * Privatise the symbols to the JDK.
+ */
+#define Z_PREFIX
+
 /*
  * If you *really* need a unique prefix for all types and library functions,
  * compile with -DZ_PREFIX. The "standard" zlib should be compiled without it.
  */
 #ifdef Z_PREFIX
-#  define deflateInit_	z_deflateInit_
-#  define deflate	z_deflate
-#  define deflateEnd	z_deflateEnd
-#  define inflateInit_ 	z_inflateInit_
-#  define inflate	z_inflate
-#  define inflateEnd	z_inflateEnd
-#  define deflateInit2_	z_deflateInit2_
-#  define deflateSetDictionary z_deflateSetDictionary
-#  define deflateCopy	z_deflateCopy
-#  define deflateReset	z_deflateReset
-#  define deflateParams	z_deflateParams
-#  define inflateInit2_	z_inflateInit2_
-#  define inflateSetDictionary z_inflateSetDictionary
-#  define inflateSync	z_inflateSync
-#  define inflateSyncPoint z_inflateSyncPoint
-#  define inflateReset	z_inflateReset
-#  define compress	z_compress
-#  define compress2	z_compress2
-#  define uncompress	z_uncompress
-#  define adler32	z_adler32
-#  define crc32		z_crc32
-#  define get_crc_table z_get_crc_table
-
-#  define Byte		z_Byte
-#  define uInt		z_uInt
-#  define uLong		z_uLong
-#  define Bytef	        z_Bytef
-#  define charf		z_charf
-#  define intf		z_intf
-#  define uIntf		z_uIntf
-#  define uLongf	z_uLongf
-#  define voidpf	z_voidpf
-#  define voidp		z_voidp
+#  define deflateInit_	_java_libz_deflateInit_
+#  define deflate	_java_libz_deflate
+#  define deflateEnd	_java_libz_deflateEnd
+#  define inflateInit_ 	_java_libz_inflateInit_
+#  define inflate	_java_libz_inflate
+#  define inflateEnd	_java_libz_inflateEnd
+#  define deflateInit2_	_java_libz_deflateInit2_
+#  define deflateSetDictionary _java_libz_deflateSetDictionary
+#  define deflateCopy	_java_libz_deflateCopy
+#  define deflateReset	_java_libz_deflateReset
+#  define deflateParams	_java_libz_deflateParams
+#  define inflateInit2_	_java_libz_inflateInit2_
+#  define inflateSetDictionary _java_libz_inflateSetDictionary
+#  define inflateSync	_java_libz_inflateSync
+#  define inflateSyncPoint _java_libz_inflateSyncPoint
+#  define inflateReset	_java_libz_inflateReset
+#  define compress	_java_libz_compress
+#  define compress2	_java_libz_compress2
+#  define uncompress	_java_libz_uncompress
+#  define adler32	_java_libz_adler32
+#  define crc32		_java_libz_crc32
+#  define get_crc_table _java_libz_get_crc_table
+
+#  define Byte		_java_libz_Byte
+#  define uInt		_java_libz_uInt
+#  define uLong		_java_libz_uLong
+#  define Bytef	        _java_libz_Bytef
+#  define charf		_java_libz_charf
+#  define intf		_java_libz_intf
+#  define uIntf		_java_libz_uIntf
+#  define uLongf	_java_libz_uLongf
+#  define voidpf	_java_libz_voidpf
+#  define voidp		_java_libz_voidp
 #endif
 
 #if (defined(_WIN32) || defined(__WIN32__)) && !defined(WIN32)
