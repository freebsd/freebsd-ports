--- configure.ac.orig	2015-07-29 15:31:05.000000000 +0200
+++ configure.ac	2015-07-29 15:31:25.000000000 +0200
@@ -199,7 +199,7 @@
         ;;
 esac
 
-PKG_CHECK_MODULES([SHELL_CORE],[libxml-2.0 >= $LIBXML_REQUIRED gtk+-$GTK_API_VERSION >= $GTK_REQUIRED gio-2.0 >= $GLIB_REQUIRED gthread-2.0 mate-desktop-2.0 >= $MATEDESKTOP_REQUIRED $SHELL_PLATFORM_PKGS])
+PKG_CHECK_MODULES([SHELL_CORE],[libxml-2.0 >= $LIBXML_REQUIRED gtk+-$GTK_API_VERSION >= $GTK_REQUIRED gio-2.0 >= $GLIB_REQUIRED gthread-2.0 $SHELL_PLATFORM_PKGS])
 
 dnl
 dnl zlib support
@@ -699,16 +699,16 @@
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
@@ -760,6 +760,23 @@
 
 AC_CHECK_FUNC(localtime_r, AC_DEFINE(HAVE_LOCALTIME_R, 1, [Defines if localtime_r is available on your system]))
 
+# *********************
+# Mate-desktop support
+# *********************
+
+AC_ARG_WITH(matedesktop,
+        [AS_HELP_STRING([--without-matedesktop],
+                        [Disable the use of matedesktop])],
+        [],
+        [with_matedesktop=yes])
+
+AM_CONDITIONAL([WITH_MATEDESKTOP],[test "$with_matedesktop" = "yes"])
+
+if test "$with_matedesktop" = "yes"; then
+        PKG_CHECK_MODULES([SHELL_CORE], mate-desktop-2.0 >= $MATEDESKTOP_REQUIRED)
+        AC_DEFINE([WITH_MATEDESKTOP],[1],[Define if mate-desktop support is enabled])
+fi
+
 # *****************
 # Help files
 # *****************
@@ -929,27 +946,28 @@
 echo "
 Configure summary:
 
-    Platform...........:    $with_platform
-    GTK+ version.......:    $with_gtk
-    GTK+ Unix Print....:    $with_gtk_unix_print
-    Keyring Support....:    $with_keyring
-    DBUS Support.......:    $enable_dbus
-    SM client support..:    $with_smclient
-    Caja Plugin........:    $enable_caja
-    Thumbnailer........:    $enable_thumbnailer
-    Previewer..........:    $enable_previewer
-    Gtk-Doc Support....:    $enable_gtk_doc
-    Debug mode.........:    $enable_debug
-    GObj. Introspection:    $enable_introspection
-    Tests..............:    $enable_tests
-
-    PDF Backend........:    $enable_pdf
-    PostScript Backend.:    $enable_ps
-    TIFF Backend.......:    $enable_tiff
-    DJVU Backend.......:    $enable_djvu
-    DVI Backend........:    $enable_dvi
-    Pixbuf Backend.....:    $enable_pixbuf
-    Comics Backend.....:    $enable_comics
-    XPS Backend........:    $enable_xps
-    ePub Backend.......:    $have_webkit
+    Platform............:    $with_platform
+    GTK+ version........:    $with_gtk
+    GTK+ Unix Print.....:    $with_gtk_unix_print
+    MATE desktop Support:    $with_matedesktop
+    Keyring Support.....:    $with_keyring
+    DBUS Support........:    $enable_dbus
+    SM client support...:    $with_smclient
+    Caja Plugin.........:    $enable_caja
+    Thumbnailer.........:    $enable_thumbnailer
+    Previewer...........:    $enable_previewer
+    Gtk-Doc Support.....:    $enable_gtk_doc
+    Debug mode..........:    $enable_debug
+    GObj. Introspection.:    $enable_introspection
+    Tests...............:    $enable_tests
+
+    PDF Backend.........:    $enable_pdf
+    PostScript Backend..:    $enable_ps
+    TIFF Backend........:    $enable_tiff
+    DJVU Backend........:    $enable_djvu
+    DVI Backend.........:    $enable_dvi
+    Pixbuf Backend......:    $enable_pixbuf
+    Comics Backend......:    $enable_comics
+    XPS Backend.........:    $enable_xps
+    ePub Backend........:    $have_webkit
 "
