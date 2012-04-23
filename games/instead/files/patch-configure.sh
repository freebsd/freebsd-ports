--- configure.sh.orig	2012-04-21 18:53:11.000000000 +0400
+++ configure.sh	2012-04-22 03:17:17.136235398 +0400
@@ -192,26 +192,7 @@
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
@@ -227,16 +208,12 @@
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
 
