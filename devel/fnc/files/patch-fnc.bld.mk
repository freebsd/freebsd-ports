--- fnc.bld.mk.orig	2022-03-04 05:14:09 UTC
+++ fnc.bld.mk
@@ -5,7 +5,7 @@
 # CONFIGURATION
 CC ?=		cc
 PREFIX ?=	/usr/local
-MANDIR ?=	/share/man
+MANDIR ?=	/man
 VERSION ?=	0.9
 
 # FLAGS NEEDED TO BUILD SQLITE3
@@ -67,8 +67,8 @@ src/fnc: src/fnc.o src/diff.o lib/libfossil.o lib/sqli
 	${FNC_LDFLAGS}
 
 install:
-	install -s -m 0755 src/fnc ${PREFIX}/bin/fnc
-	install -m 0644 src/fnc.1 ${PREFIX}${MANDIR}/man1/fnc.1
+	install -s -m 0755 src/fnc ${DESTDIR}${PREFIX}/bin/fnc
+	install -m 0644 src/fnc.1 ${DESTDIR}${PREFIX}${MANDIR}/man1/fnc.1
 
 uninstall:
 	rm -f ${PREFIX}/bin/fnc ${PREFIX}${MANDIR}/man1/fnc.1
