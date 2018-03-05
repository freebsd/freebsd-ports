--- config.sh.orig	2018-02-19 15:16:29 UTC
+++ config.sh
@@ -28,9 +28,11 @@ while [ $# -gt 0 ] ; do
     case $1 in
     --without-curses)   WITHOUT_CURSES=1 ;;
     --without-gtk)      WITHOUT_GTK=1 ;;
+    --with-gtk=*)       GTKVER=`echo $1 | sed -e 's/--with-gtk=//'` ;;
     --without-win32)    WITHOUT_WIN32=1 ;;
     --with-kde4)        WITHOUT_KDE4=0 ;;
     --without-qt4)      WITHOUT_QT4=1 ;;
+    --without-qt5)      WITHOUT_QT5=1 ;;
     --without-ansi)     WITHOUT_ANSI=1 ;;
     --help)             CONFIG_HELP=1 ;;
 
@@ -59,9 +61,11 @@ if [ "$CONFIG_HELP" = "1" ] ; then
     echo "--prefix=PREFIX       Installation prefix ($PREFIX)."
     echo "--without-curses      Disable curses (text) interface detection."
     echo "--without-gtk         Disable GTK interface detection."
+    echo "--with-gtk=GTKVER     Enable GTK where GTKVER=(2|3)."
     echo "--without-win32       Disable win32 interface detection."
     echo "--with-kde4           Enable KDE4 interface detection."
     echo "--without-qt4         Disable Qt4 interface detection."
+    echo "--without-qt5         Disable Qt5 interface detection."
     echo "--with-moc            Path to your QT4 moc. Ie: --with-moc=/usr/lib64/qt4/bin/moc"
     echo "--without-ansi        Disable ANSI terminal interface detection."
     echo "--without-unix-glob   Disable glob.h usage (use workaround)."
@@ -223,36 +227,11 @@ echo -n "Testing for ncursesw... "
 if [ "$WITHOUT_CURSES" = "1" ] ; then
     echo "Disabled"
 else
-    echo "#include <ncursesw/ncurses.h>" > .tmp.c
-    echo "int main(void) { initscr(); endwin(); return 0; }" >> .tmp.c
-
-    TMP_CFLAGS="-I/usr/local/include -I/usr/include/ncurses -I/usr/include/ncursesw"
-    TMP_LDFLAGS="-L/usr/local/lib -lncursesw"
-
-    $CC $TMP_CFLAGS .tmp.c $TMP_LDFLAGS -o .tmp.o 2>> .config.log
-    if [ $? = 0 ] ; then
-        echo "#define CONFOPT_CURSES 1" >> config.h
-        echo $TMP_CFLAGS >> config.cflags
-        echo $TMP_LDFLAGS >> config.ldflags
-        echo "OK (ncursesw)"
-        DRIVERS="ncursesw $DRIVERS"
-        DRV_OBJS="mpv_curses.o $DRV_OBJS"
-        WITHOUT_ANSI=1
-    else
-        echo "No"
-        WITHOUT_CURSES=1
-    fi
-fi
-
-if [ "$WITHOUT_CURSES" = "1" ] ; then
-    # test for curses / ncurses library
-    echo -n "Testing for recent ncurses... "
-
     echo "#include <ncurses.h>" > .tmp.c
     echo "int main(void) { initscr(); endwin(); return 0; }" >> .tmp.c
 
-    TMP_CFLAGS="-I/usr/local/include"
-    TMP_LDFLAGS="-L/usr/local/lib -lncursesw"
+    TMP_CFLAGS="-I${NCURSESINC}"
+    TMP_LDFLAGS="${LDFLAGS} -L${NCURSESLIB} -lncursesw"
 
     $CC $TMP_CFLAGS .tmp.c $TMP_LDFLAGS -o .tmp.o 2>> .config.log
     if [ $? = 0 ] ; then
@@ -384,19 +363,22 @@ if [ "$WITHOUT_QT5" = "1" ] ; then
 else
     if which pkg-config > /dev/null 2>&1
     then
-        if which moc-qt5 > /dev/null 2>&1
-        then
-            MOC=moc-qt5
-            echo "MOC=$MOC" >> makefile.opts
+	if [ ! $QT4MOC ]; then
+		MOC="moc"
+	else
+        	MOC="$QT4MOC"
+	fi
+        which moc-qt5 > /dev/null 2>&1 && MOC=moc-qt5
+        echo "MOC=$MOC" >> makefile.opts
 
-            TMP_CFLAGS="$(pkg-config --cflags Qt5Widgets) -fPIC"
-            TMP_LDFLAGS=$(pkg-config --libs Qt5Widgets)
+            TMP_CFLAGS="$(pkg-config --cflags Qt5Widgets) $(pkg-config --cflags gl) -fPIC"
+            TMP_LDFLAGS="$(pkg-config --libs Qt5Widgets) $(pkg-config --libs gl)"
 
             echo "#include <QtWidgets>" > .tmp.cpp
             echo "int main(int argc, char *argv[]) { new QApplication(argc, argv) ; return 0; } " >> .tmp.cpp
  
-            echo "$CPP $TMP_CFLAGS .tmp.cpp $TMP_LDFLAGS -o .tmp.o" >> .config.log
-            $CPP $TMP_CFLAGS .tmp.cpp $TMP_LDFLAGS -o .tmp.o 2>> .config.log
+            echo "$CPP $CXXFLAGS $TMP_CFLAGS .tmp.cpp $TMP_LDFLAGS -o .tmp.o" >> .config.log
+            $CPP $CXXFLAGS $TMP_CFLAGS .tmp.cpp $TMP_LDFLAGS -o .tmp.o 2>> .config.log
 
             if [ $? = 0 ] ; then
                 echo $TMP_CFLAGS >> config.cflags
@@ -416,9 +398,6 @@ else
             else
                 echo "No"
             fi
-        else
-            echo "No"
-        fi
     else
         echo "No"
     fi
@@ -441,8 +420,8 @@ else
         which moc-qt4 > /dev/null 2>&1 && MOC=moc-qt4
         echo "MOC=$MOC" >> makefile.opts
 
-        TMP_CFLAGS=$(pkg-config --cflags QtGui)
-        TMP_LDFLAGS="$(pkg-config --libs QtGui) -lX11"
+        TMP_CFLAGS="$(pkg-config --cflags QtGui) $(pkg-config --cflags x11)"
+        TMP_LDFLAGS="$(pkg-config --libs QtGui) $(pkg-config --libs x11)"
 
         echo "#include <QtGui>" > .tmp.cpp
         echo "int main(int argc, char *argv[]) { new QApplication(argc, argv) ; return 0; } " >> .tmp.cpp
@@ -483,15 +462,15 @@ else
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
