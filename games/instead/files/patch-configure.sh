--- configure.sh.orig	2012-02-09 18:55:00.127534293 +0400
+++ configure.sh	2012-02-09 18:58:52.803532634 +0400
@@ -131,14 +131,14 @@
 echo -n "Checking iconv...("
 echo -n "$cc /tmp/iconv-test.c -o iconv-test)..."
 
-if $cc /tmp/iconv-test.c -o /tmp/iconv-test; then
+if $cc /tmp/iconv-test.c -o /tmp/iconv-test >/dev/null 2>&1; then
 	CFLAGS="$CFLAGS -D_HAVE_ICONV"
 	echo "ok"
-elif $cc /tmp/iconv-test.c -liconv -o /tmp/iconv-test; then
+elif $cc /tmp/iconv-test.c -liconv -o /tmp/iconv-test >/dev/null 2>&1; then
 	CFLAGS="$CFLAGS -D_HAVE_ICONV"
 	LDFLAGS="$LDFLAGS -liconv"
 	echo "ok, with -liconv"
-elif $cc /tmp/iconv-test.c -I/usr/local/include -L/usr/local/lib -liconv -o /tmp/iconv-test; then
+elif $cc /tmp/iconv-test.c -I/usr/local/include -L/usr/local/lib -liconv -o /tmp/iconv-test >/dev/null 2>&1; then
 	CFLAGS="$CFLAGS -I/usr/local/include -D_HAVE_ICONV"
 	LDFLAGS="$LDFLAGS -L/usr/local/lib -liconv"
 	echo "ok, with -liconv and -L/usr/local/lib"
@@ -183,26 +183,7 @@
 echo "SDL_CFLAGS=\$(shell sdl-config --cflags)" >> config.make
 echo "SDL_LFLAGS=\$(shell sdl-config --libs) -lSDL_ttf -lSDL_mixer -lSDL_image" >> config.make
 echo "ok"
-echo -n "Choose installation mode. Standalone(1) or system(2) [1]: "
-read ans
-if [ "x$ans" = "x1" -o "x$ans" = "x" ]; then
-	echo " * Standalone version"
-	rm -f Rules.make
-	ln -sf Rules.make.standalone Rules.make
-	rm -f sdl-instead
-	ln -sf src/sdl-instead/sdl-instead sdl-instead
-	echo "Ok. We are ready to build. Use these commands:"
-	echo "    \$ make"
-	echo "    \$ ./sdl-instead"
-elif [ "x$ans" = "x2" ]; then
-	echo -n "Enter prefix path [/usr/local]: "
-	read ans
-
-	if [ "x$ans" = "x" ]; then
-		prefix="/usr/local"
-	else
-		prefix="$ans"
-	fi
+	prefix="$PREFIX"
 	
 	rm -f Rules.make
 	ln -s Rules.make.system Rules.make
@@ -218,16 +199,12 @@
 	echo "ICONPATH=\$(DESTDIR)\$(PREFIX)/share/pixmaps" >> config.make
 	echo "DOCPATH=\$(DESTDIR)\$(PREFIX)/share/doc/instead" >> config.make
 	echo "LANGPATH=\$(DATAPATH)/lang" >> config.make
-	echo "MANPATH=\$(DESTDIR)\$(PREFIX)/share/man/man6" >> config.make
+	echo "MANPATH=\$(DESTDIR)\$(PREFIX)/man/man6" >> config.make
 
 	echo "Ok. We are ready to build and install. Use these commands:"
 	echo "    \$ make"
 	echo "    \$ sudo make install"
 	echo "    \$ sdl-instead"
-else
-	echo "Huh!!! Wrong answer."
-	exit 1
-fi
 
 echo " Enjoy..."
 
