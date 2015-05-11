--- build/install.sh.orig	2014-10-21 11:41:15 UTC
+++ build/install.sh
@@ -26,8 +26,8 @@ SAVED_LIBDIR="${LIBDIR}"
 
 . ./config.sh
 
-BINDIR="${SAVED_BINDIR:-${BINDIR}}"
-LIBDIR="${SAVED_LIBDIR:-${LIBDIR}}"
+BINDIR="${DESTDIR}${SAVED_BINDIR:-${BINDIR}}"
+LIBDIR="${DESTDIR}${SAVED_LIBDIR:-${LIBDIR}}"
 
 not_installed=$PWD/_build/not_installed
 
