--- configure.ac.orig	2015-09-04 11:33:09.197403000 +0200
+++ configure.ac	2015-09-04 11:33:38.935108000 +0200
@@ -697,16 +697,16 @@
     case "$with_gtk" in
         2.0)
         PKG_CHECK_MODULES(EPUB, webkit-$WEBKIT_API_VERSION >= $WEBKIT_REQUIRED \
-	    libxml-2.0 >= $LIBXML_REQUIRED zlib,have_webkit=yes,have_webkit=no)
+	    libxml-2.0 >= $LIBXML_REQUIRED ,have_webkit=yes,have_webkit=no)
 	;;
         3.0)
         PKG_CHECK_MODULES(EPUB, webkit2gtk-$WEBKIT_API_VERSION >= $WEBKIT_REQUIRED \
-	    libxml-2.0 >= $LIBXML_REQUIRED zlib,have_webkit=yes,have_webkit=no)
+	    libxml-2.0 >= $LIBXML_REQUIRED ,have_webkit=yes,have_webkit=no)
         if test "x$have_webkit" = "xno"; then
 	   AC_MSG_NOTICE([Webkit2 4.0 not found, trying 3.0])
            WEBKIT_API_VERSION=3.0
            PKG_CHECK_MODULES(EPUB, webkit2gtk-$WEBKIT_API_VERSION >= $WEBKIT_REQUIRED \
-	       libxml-2.0 >= $LIBXML_REQUIRED zlib,have_webkit=yes,have_webkit=no)
+	       libxml-2.0 >= $LIBXML_REQUIRED ,have_webkit=yes,have_webkit=no)
         fi
 	;;
 esac
