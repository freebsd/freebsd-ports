--- config.sh.orig	2019-07-02 05:57:45 UTC
+++ config.sh
@@ -40,6 +40,7 @@ while [ $# -gt 0 ] ; do
     case $1 in
     --without-curses)    WITHOUT_CURSES=1 ;;
     --without-gtk)       WITHOUT_GTK=1 ;;
+    --with-gtk=*)        GTKVER=`echo $1 | sed -e 's/--with-gtk=//'` ;;
     --without-win32)     WITHOUT_WIN32=1 ;;
     --with-kde4)         WITHOUT_KDE4=0 ;;
     --without-qt)        WITHOUT_QT5=1 && WITHOUT_QT4=1 ;;
@@ -75,6 +76,7 @@ if [ "$CONFIG_HELP" = "1" ] ; then
     echo "--prefix=PREFIX         Installation prefix ($PREFIX)."
     echo "--without-curses        Disable curses (text) interface detection."
     echo "--without-gtk           Disable GTK interface detection."
+    echo "--with-gtk=GTKVER       Enable GTK where GTKVER=(2|3)."
     echo "--without-win32         Disable win32 interface detection."
     echo "--with-kde4             Enable KDE4 interface detection."
     echo "--without-qt            Disable Qt interface detection."
@@ -250,11 +252,11 @@ echo -n "Testing for ncursesw... "
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
 
     $CC $TMP_CFLAGS .tmp.c $TMP_LDFLAGS -o .tmp.o 2>> .config.log
     if [ $? = 0 ] ; then
@@ -384,14 +386,14 @@ if [ "$WITHOUT_QT5" = "1" ] ; then
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
@@ -475,15 +477,15 @@ else
     echo "int main(void) { gtk_main(); return 0; } " >> .tmp.c
 
     # Try first GTK 3.0
-    TMP_CFLAGS=`sh -c 'pkg-config --cflags gtk+-3.0' 2>/dev/null`
-    TMP_LDFLAGS=`sh -c 'pkg-config --libs gtk+-3.0' 2>/dev/null`
+    TMP_CFLAGS=`sh -c "pkg-config --cflags gtk+-$GTKVER.0" 2>/dev/null`
+    TMP_LDFLAGS=`sh -c "pkg-config --libs gtk+-$GTKVER.0" 2>/dev/null`
 
     $CC $TMP_CFLAGS .tmp.c $TMP_LDFLAGS -o .tmp.o 2>> .config.log
     if [ $? = 0 ] ; then
-        echo "#define CONFOPT_GTK 3" >> config.h
+        echo "#define CONFOPT_GTK $GTKVER" >> config.h
         echo "$TMP_CFLAGS " >> config.cflags
         echo "$TMP_LDFLAGS " >> config.ldflags
-        echo "OK (3.0)"
+        echo "OK ($GTKVER.0)"
         DRIVERS="gtk $DRIVERS"
         DRV_OBJS="mpv_gtk.o $DRV_OBJS"
     else
