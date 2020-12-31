--- config.sh.orig	2020-10-11 16:57:43 UTC
+++ config.sh
@@ -37,6 +37,7 @@ while [ $# -gt 0 ] ; do
     case $1 in
     --without-curses)    WITHOUT_CURSES=1 ;;
     --without-gtk)       WITHOUT_GTK=1 ;;
+    --with-gtk=*)        GTKVER=`echo $1 | sed -e 's/--with-gtk=//'` ;;
     --without-win32)     WITHOUT_WIN32=1 ;;
     --with-kde4)         WITHOUT_KDE4=0 ;;
     --without-qt)        WITHOUT_QT5=1 && WITHOUT_QT4=1 ;;
@@ -46,6 +47,9 @@ while [ $# -gt 0 ] ; do
     --without-ansi)      WITHOUT_ANSI=1 ;;
     --with-external-arch) WITH_EXTERNAL_ARCH=1 ;;
     --with-external-tar) WITH_EXTERNAL_ARCH=1 ;;
+    --with-docs)         MORE_TARGETS="docs $MORE_TARGETS" ;; 
+    --with-gettext)      WITHOUT_MSGFMT=0 ;;
+    --with-manpages)     MORE_TARGETS="mp-5.1 $MORE_TARGETS" ;;
     --without-zip)       WITHOUT_ZIP=1 ;;
     --help)              CONFIG_HELP=1 ;;
 
@@ -73,6 +77,7 @@ if [ "$CONFIG_HELP" = "1" ] ; then
     echo "--prefix=PREFIX         Installation prefix ($PREFIX)."
     echo "--without-curses        Disable curses (text) interface detection."
     echo "--without-gtk           Disable GTK interface detection."
+    echo "--with-gtk=GTKVER       Enable GTK where GTKVER=(2|3)."
     echo "--without-win32         Disable win32 interface detection."
     echo "--with-kde4             Enable KDE4 interface detection."
     echo "--without-qt            Disable Qt interface detection."
@@ -207,9 +212,6 @@ echo
 (cd $MPSL && ./config.sh --prefix=$PREFIX --docdir=$PREFIX/share/doc/$APPNAME $CONF_ARGS)
 echo
 
-# import MPSL build configuration
-[ -f "$MPSL.build.sh" ] && . $MPSL.build.sh
-
 cat $MPDM/config.ldflags >> config.ldflags
 cat $MPSL/config.ldflags >> config.ldflags
 
@@ -248,11 +250,11 @@ echo -n "Testing for ncursesw... "
 if [ "$WITHOUT_CURSES" = "1" ] ; then
     echo "Disabled"
 else
-    echo "#include <ncursesw/ncurses.h>" > .tmp.c
+    echo "#include <ncurses.h>" > .tmp.c
     echo "int main(void) { initscr(); endwin(); return 0; }" >> .tmp.c
 
-    TMP_CFLAGS="-I/usr/local/include -I/usr/include/ncurses -I/usr/include/ncursesw"
-    TMP_LDFLAGS="-L/usr/local/lib -lncursesw"
+    TMP_CFLAGS="-I${NCURSESINC}"
+    TMP_LDFLAGS="${LDFLAGS} -L${NCURSESLIB} -lncursesw"
 
     $CC $CFLAGS $TMP_CFLAGS .tmp.c $TMP_LDFLAGS -o .tmp.o 2>> .config.log
     if [ $? = 0 ] ; then
@@ -386,14 +388,14 @@ if [ "$WITHOUT_QT5" = "1" ] ; then
 else
     if which pkg-config > /dev/null 2>&1
     then
-        TMP_CFLAGS="`sh -c 'pkg-config --cflags Qt5Widgets' 2>/dev/null` -fPIC"
-        TMP_LDFLAGS="`sh -c 'pkg-config --libs Qt5Widgets' 2>/dev/null`"
+        TMP_CFLAGS="`sh -c 'pkg-config --cflags Qt5Widgets gl' 2>/dev/null` -fPIC"
+        TMP_LDFLAGS="`sh -c 'pkg-config --libs Qt5Widgets gl' 2>/dev/null`"
 
         echo "#include <QtWidgets>" > .tmp.cpp
         echo "int main(int argc, char *argv[]) { new QApplication(argc, argv) ; return 0; } " >> .tmp.cpp
  
-        echo "$CPP $TMP_CFLAGS .tmp.cpp $TMP_LDFLAGS -o .tmp.o" >> .config.log
-        $CPP $TMP_CFLAGS .tmp.cpp $TMP_LDFLAGS -o .tmp.o 2>> .config.log
+        echo "$CPP $CXXFLAGS $TMP_CFLAGS .tmp.cpp $TMP_LDFLAGS -o .tmp.o" >> .config.log
+        $CPP $CXXFLAGS $TMP_CFLAGS .tmp.cpp $TMP_LDFLAGS -o .tmp.o 2>> .config.log
 
         if [ $? = 0 ] ; then
             echo $TMP_CFLAGS >> config.cflags
@@ -479,15 +481,15 @@ else
     echo "int main(void) { gtk_main(); return 0; } " >> .tmp.c
 
     # Try first GTK 3.0
-    TMP_CFLAGS=`sh -c 'pkg-config --cflags gtk+-3.0' 2>/dev/null`
-    TMP_LDFLAGS=`sh -c 'pkg-config --libs gtk+-3.0' 2>/dev/null`
+    TMP_CFLAGS=`sh -c "pkg-config --cflags gtk+-$GTKVER.0" 2>/dev/null`
+    TMP_LDFLAGS=`sh -c "pkg-config --libs gtk+-$GTKVER.0" 2>/dev/null`
 
     $CC $CFLAGS $TMP_CFLAGS .tmp.c $TMP_LDFLAGS -o .tmp.o 2>> .config.log
     if [ $? = 0 ] ; then
-        echo "#define CONFOPT_GTK 3" >> config.h
+        echo "#define CONFOPT_GTK $GTKVER" >> config.h
         echo "$TMP_CFLAGS " >> config.cflags
         echo "$TMP_LDFLAGS " >> config.ldflags
-        echo "OK (3.0)"
+        echo "OK ($GTKVER.0)"
         DRIVERS="gtk $DRIVERS"
         DRV_OBJS="mpv_gtk.o $DRV_OBJS"
         CFLAGS="$CFLAGS $TMP_CFLAGS"
@@ -625,7 +627,7 @@ if [ "$WITH_EXTERNAL_ARCH" = "1" ] ; then
     echo "#define CONFOPT_EXTERNAL_ARCH 1" >> config.h
     echo "#define ARCH_START NULL" >> config.h
     echo "#define ARCH_END NULL" >> config.h
-    MORE_TARGETS="mp.tar"
+    MORE_TARGETS="mp.tar $MORE_TARGETS"
     MORE_INSTALL_TARGETS="install-tar $MORE_INSTALL_TARGETS"
 fi
 
