--- fnc.bld.mk.orig	2024-09-25 08:28:03 UTC
+++ fnc.bld.mk
@@ -4,7 +4,7 @@ CC ?=		cc
 
 # CONFIGURATION
 CC ?=		cc
-PREFIX ?=	/usr/local
+PREFIX ?=	%%PREFIX%%
 MANDIR ?=	/share/man
 VERSION ?=	%%VERSION%%
 HASH !=		cut -f 1 manifest.uuid
@@ -114,10 +114,10 @@ install:
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
