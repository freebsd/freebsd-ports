--- ext/standard/image.c.orig	2013-12-10 19:32:43.000000000 +0000
+++ ext/standard/image.c	2013-12-13 21:55:54.112235824 +0000
@@ -31,9 +31,7 @@
 #endif
 #include "php_image.h"
 
-#if HAVE_ZLIB && !defined(COMPILE_DL_ZLIB)
 #include "zlib.h"
-#endif
 
 /* file type markers */
 PHPAPI const char php_sig_gif[3] = {'G', 'I', 'F'};
@@ -81,9 +79,7 @@ PHP_MINIT_FUNCTION(imagetypes)
 	REGISTER_LONG_CONSTANT("IMAGETYPE_JP2",     IMAGE_FILETYPE_JP2,     CONST_CS | CONST_PERSISTENT);
 	REGISTER_LONG_CONSTANT("IMAGETYPE_JPX",     IMAGE_FILETYPE_JPX,     CONST_CS | CONST_PERSISTENT);
 	REGISTER_LONG_CONSTANT("IMAGETYPE_JB2",     IMAGE_FILETYPE_JB2,     CONST_CS | CONST_PERSISTENT);
-#if HAVE_ZLIB && !defined(COMPILE_DL_ZLIB)
 	REGISTER_LONG_CONSTANT("IMAGETYPE_SWC",     IMAGE_FILETYPE_SWC,     CONST_CS | CONST_PERSISTENT);
-#endif	
 	REGISTER_LONG_CONSTANT("IMAGETYPE_IFF",     IMAGE_FILETYPE_IFF,     CONST_CS | CONST_PERSISTENT);
 	REGISTER_LONG_CONSTANT("IMAGETYPE_WBMP",    IMAGE_FILETYPE_WBMP,    CONST_CS | CONST_PERSISTENT);
 	REGISTER_LONG_CONSTANT("IMAGETYPE_JPEG2000",IMAGE_FILETYPE_JPC,     CONST_CS | CONST_PERSISTENT); /* keep alias */
@@ -188,7 +184,6 @@ static unsigned long int php_swf_get_bit
 }
 /* }}} */
 
-#if HAVE_ZLIB && !defined(COMPILE_DL_ZLIB)
 /* {{{ php_handle_swc
  */
 static struct gfxinfo *php_handle_swc(php_stream * stream TSRMLS_DC)
@@ -259,7 +254,6 @@ static struct gfxinfo *php_handle_swc(ph
 	return result;
 }
 /* }}} */
-#endif
 
 /* {{{ php_handle_swf
  */
@@ -1318,11 +1312,7 @@ static void php_getimagesize_from_stream
 			result = php_handle_swf(stream TSRMLS_CC);
 			break;
 		case IMAGE_FILETYPE_SWC:
-#if HAVE_ZLIB && !defined(COMPILE_DL_ZLIB)
 			result = php_handle_swc(stream TSRMLS_CC);
-#else
-			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "The image is a compressed SWF file, but you do not have a static version of the zlib extension enabled");
-#endif
 			break;
 		case IMAGE_FILETYPE_PSD:
 			result = php_handle_psd(stream TSRMLS_CC);
