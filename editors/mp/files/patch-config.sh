--- config.sh.orig	2022-02-03 09:30:31 UTC
+++ config.sh
@@ -40,6 +40,7 @@ while [ $# -gt 0 ] ; do
     case $1 in
     --without-curses)    WITHOUT_CURSES=1 ;;
     --without-gtk)       WITHOUT_GTK=1 ;;
+    --with-gtk=*)        GTKVER=`echo $1 | sed -e 's/--with-gtk=//'` ;;
     --without-win32)     WITHOUT_WIN32=1 ;;
     --with-kde4)         WITHOUT_KDE4=0 ;;
     --without-qt)        WITHOUT_QT5=1 && WITHOUT_QT4=1 ;;
@@ -49,6 +50,9 @@ while [ $# -gt 0 ] ; do
     --without-ansi)      WITHOUT_ANSI=1 ;;
     --with-external-arch) WITH_EXTERNAL_ARCH=1 ;;
     --with-external-tar) WITH_EXTERNAL_ARCH=1 ;;
+    --with-docs)         MORE_TARGETS="docs $MORE_TARGETS" ;; 
+    --with-gettext)      WITHOUT_MSGFMT=0 ;;
+    --with-manpages)     MORE_TARGETS="mp-5.1 $MORE_TARGETS" ;;
     --without-zip)       WITHOUT_ZIP=1 ;;
     --help)              CONFIG_HELP=1 ;;
 
@@ -76,6 +80,7 @@ if [ "$CONFIG_HELP" = "1" ] ; then
     echo "--prefix=PREFIX         Installation prefix ($PREFIX)."
     echo "--without-curses        Disable curses (text) interface detection."
     echo "--without-gtk           Disable GTK interface detection."
+    echo "--with-gtk=GTKVER       Enable GTK where GTKVER=(2|3)."
     echo "--without-win32         Disable win32 interface detection."
     echo "--with-kde4             Enable KDE4 interface detection."
     echo "--without-qt            Disable Qt interface detection."
@@ -225,9 +230,6 @@ echo
 (cd $MPSL && ./config.sh --prefix=$PREFIX --docdir=$PREFIX/share/doc/$APPNAME $CONF_ARGS)
 echo
 
-# import MPSL build configuration
-[ -f "$MPSL.build.sh" ] && . $MPSL.build.sh
-
 cat $MPDM/config.ldflags >> config.ldflags
 cat $MPSL/config.ldflags >> config.ldflags
 
@@ -286,8 +288,8 @@ else
         TMP_CFLAGS="$(ncurses5-config --cflags)"
         TMP_LDFLAGS="$(ncurses5-config --libs)"
     else
-        TMP_CFLAGS=
-        TMP_LDFLAGS=-lncurses
+        TMP_CFLAGS="-I${NCURSESINC}"
+        TMP_LDFLAGS="${LDFLAGS} -L${NCURSESLIB} -lncursesw"
     fi
 
     if chk_compiles "$(cat <<EOF
@@ -451,8 +453,8 @@ if [ "$WITHOUT_QT5" = "1" ] ; then
 else
     if chk_pkgconfig Qt5Widgets
     then
-        TMP_CFLAGS="$(${PKG_CONFIG} --cflags Qt5Widgets 2>/dev/null) -fPIC"
-        TMP_LDFLAGS="$(${PKG_CONFIG} --libs Qt5Widgets 2>/dev/null)"
+        TMP_CFLAGS="$(${PKG_CONFIG} --cflags Qt5Widgets gl 2>/dev/null) -fPIC"
+        TMP_LDFLAGS="$(${PKG_CONFIG} --libs Qt5Widgets gl 2>/dev/null)"
 
         if USE_CXX=true chk_compiles "$(cat <<EOF
 #include <QtWidgets>
@@ -541,8 +543,8 @@ if [ "$WITHOUT_GTK" = "1" ] ; then
 else
     # Try first GTK 3.0
     if chk_pkgconfig gtk+-3.0 ; then
-        TMP_CFLAGS="$(${PKG_CONFIG} --cflags gtk+-3.0 2>/dev/null)"
-        TMP_LDFLAGS="$(${PKG_CONFIG} --libs gtk+-3.0 2>/dev/null)"
+        TMP_CFLAGS="$(${PKG_CONFIG} --cflags gtk+-$GTKVER.0 2>/dev/null)"
+        TMP_LDFLAGS="$(${PKG_CONFIG} --libs gtk+-$GTKVER.0 2>/dev/null)"
 
         if chk_compiles "$(cat <<EOF
 #include <gtk/gtk.h>
@@ -550,10 +552,10 @@ else
 int main(void) { gtk_main(); return 0; }
 EOF
 )" ; then
-            echo "#define CONFOPT_GTK 3" >> config.h
+            echo "#define CONFOPT_GTK $GTKVER" >> config.h
             echo "$TMP_CFLAGS " >> config.cflags
             echo "$TMP_LDFLAGS " >> config.ldflags
-            echo "OK (3.0)"
+            echo "OK ($GTKVER.0)"
             DRIVERS="gtk $DRIVERS"
             DRV_OBJS="mpv_gtk.o $DRV_OBJS"
             CFLAGS="$CFLAGS $TMP_CFLAGS"
@@ -704,7 +706,7 @@ if [ "$WITH_EXTERNAL_ARCH" = "1" ] ; then
     echo "#define CONFOPT_EXTERNAL_ARCH 1" >> config.h
     echo "#define ARCH_START NULL" >> config.h
     echo "#define ARCH_END NULL" >> config.h
-    MORE_TARGETS="$ARCH_FILE"
+    MORE_TARGETS="$ARCH_FILE $MORE_TARGETS"
     MORE_INSTALL_TARGETS="install-arch $MORE_INSTALL_TARGETS"
 fi
 
