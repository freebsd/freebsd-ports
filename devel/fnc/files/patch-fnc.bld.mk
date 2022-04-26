--- fnc.bld.mk.orig	2022-03-24 19:30:04 UTC
+++ fnc.bld.mk
@@ -5,7 +5,7 @@
 # CONFIGURATION
 CC ?=		cc
 PREFIX ?=	/usr/local
-MANDIR ?=	/share/man
+MANDIR ?=	/man
 VERSION ?=	%%VERSION%%
 
 # FLAGS NEEDED TO BUILD SQLITE3
@@ -67,9 +67,9 @@ src/fnc: src/fnc.o src/diff.o lib/libfossil.o lib/sqli
 	${FNC_LDFLAGS}
 
 install:
-	mkdir -p -m 0755 ${PREFIX}${MANDIR}/man1
-	install -s -m 0755 src/fnc ${PREFIX}/bin/fnc
-	install -m 0644 src/fnc.1 ${PREFIX}${MANDIR}/man1/fnc.1
+	mkdir -p -m 0755 ${DESTDIR}${PREFIX}${MANDIR}/man1
+	install -s -m 0755 src/fnc ${DESTDIR}${PREFIX}/bin/fnc
+	install -m 0644 src/fnc.1 ${DESTDIR}${PREFIX}${MANDIR}/man1/fnc.1
 
 uninstall:
 	rm -f ${PREFIX}/bin/fnc ${PREFIX}${MANDIR}/man1/fnc.1
