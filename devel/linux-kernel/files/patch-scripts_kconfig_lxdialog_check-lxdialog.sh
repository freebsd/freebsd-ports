--- scripts/kconfig/lxdialog/check-lxdialog.sh.orig	2016-07-27 15:42:34 UTC
+++ scripts/kconfig/lxdialog/check-lxdialog.sh
@@ -4,39 +4,14 @@
 # What library to link
 ldflags()
 {
-	pkg-config --libs ncursesw 2>/dev/null && exit
-	pkg-config --libs ncurses 2>/dev/null && exit
-	for ext in so a dll.a dylib ; do
-		for lib in ncursesw ncurses curses ; do
-			$cc -print-file-name=lib${lib}.${ext} | grep -q /
-			if [ $? -eq 0 ]; then
-				echo "-l${lib}"
-				exit
-			fi
-		done
-	done
-	exit 1
+	echo "-lncursesw"
+	exit
 }
 
 # Where is ncurses.h?
 ccflags()
 {
-	if pkg-config --cflags ncursesw 2>/dev/null; then
-		echo '-DCURSES_LOC="<ncurses.h>" -DNCURSES_WIDECHAR=1'
-	elif pkg-config --cflags ncurses 2>/dev/null; then
-		echo '-DCURSES_LOC="<ncurses.h>"'
-	elif [ -f /usr/include/ncursesw/curses.h ]; then
-		echo '-I/usr/include/ncursesw -DCURSES_LOC="<curses.h>"'
-		echo ' -DNCURSES_WIDECHAR=1'
-	elif [ -f /usr/include/ncurses/ncurses.h ]; then
-		echo '-I/usr/include/ncurses -DCURSES_LOC="<ncurses.h>"'
-	elif [ -f /usr/include/ncurses/curses.h ]; then
-		echo '-I/usr/include/ncurses -DCURSES_LOC="<curses.h>"'
-	elif [ -f /usr/include/ncurses.h ]; then
-		echo '-DCURSES_LOC="<ncurses.h>"'
-	else
-		echo '-DCURSES_LOC="<curses.h>"'
-	fi
+	echo '-DCURSES_LOC="<ncurses.h>" -DNCURSES_WIDECHAR=1'
 }
 
 # Temp file, try to clean up after us
