--- fnc.bld.mk.orig	2023-11-27 08:16:26 UTC
+++ fnc.bld.mk
@@ -4,8 +4,8 @@ CC ?=		cc
 
 # CONFIGURATION
 CC ?=		cc
-PREFIX ?=	/usr/local
-MANDIR ?=	/share/man
+PREFIX ?=	%%PREFIX%%
+MANDIR ?=	/man
 VERSION ?=	%%VERSION%%
 HASH !=		cut -f 1 manifest.uuid
 DATE !=		sed '2q;d' manifest | cut -d ' ' -f 2 | tr T ' '
@@ -42,7 +42,7 @@ FOSSIL_CFLAGS =	${CFLAGS} -Wall -Werror -Wsign-compare
 # On SOME Linux (e.g., Ubuntu 18.04.6), we have to include wchar curses from
 # I/.../ncursesw, but linking to -lncursesw (w/ no special -L path) works fine.
 # FLAGS NEEDED TO BUILD FNC
-FNC_CFLAGS =	${CFLAGS} -Wall -Werror -Wsign-compare -pedantic -std=c99 \
+FNC_CFLAGS =	${CFLAGS} -Wall -Werror -Wsign-compare -pedantic -std=c11 \
 		-I./lib -I./include -I/usr/include/ncursesw \
 		-D_XOPEN_SOURCE_EXTENDED -DVERSION=${VERSION} -DHASH=${HASH} \
 		-DDATE="${DATE}"
@@ -89,10 +89,10 @@ install:
 	@echo "generated compile_commands.json"
 
 install:
-	mkdir -p -m 0755 ${PREFIX}/bin
-	mkdir -p -m 0755 ${PREFIX}${MANDIR}/man1
-	install -s -m 0755 src/fnc ${PREFIX}/bin/fnc
-	install -m 0644 src/fnc.1 ${PREFIX}${MANDIR}/man1/fnc.1
+	mkdir -p -m 0755 ${DESTDIR}${PREFIX}/bin
+	mkdir -p -m 0755 ${DESTDIR}${PREFIX}${MANDIR}/man1
+	install -s -m 0755 src/fnc ${DESTDIR}${PREFIX}/bin/fnc
+	install -m 0644 src/fnc.1 ${DESTDIR}${PREFIX}${MANDIR}/man1/fnc.1
 
 uninstall:
 	rm -f ${PREFIX}/bin/fnc ${PREFIX}${MANDIR}/man1/fnc.1
