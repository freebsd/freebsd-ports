--- fnc.bld.mk.orig	2026-01-23 20:37:32 UTC
+++ fnc.bld.mk
@@ -4,7 +4,7 @@ CC ?=		cc
 
 # CONFIGURATION
 CC ?=		cc
-PREFIX ?=	/usr/local
+PREFIX ?=	%%PREFIX%%
 MANDIR ?=	/share/man
 VERSION ?=	%%VERSION%%
 HASH !=		cut -f 1 manifest.uuid
@@ -47,7 +47,7 @@ FNC_CFLAGS =	${CFLAGS} -Wstrict-prototypes -Wmissing-p
 		-Wunused-variable -I./lib -I./include -I/usr/include/ncursesw \
 		-DFNC_VERSION=${VERSION} -DFNC_HASH=${HASH} -DFNC_DATE="${DATE}"
 
-FNC_LDFLAGS =	${LDFLAGS} -lm -lutil -lz -lpthread
+FNC_LDFLAGS =	${LDFLAGS} -lm -lutil -lz -lpthread -lsqlite3
 
 # Compile-time checks and runtime protection mechanisms from the compiler
 # hardening document: https://best.openssf.org/Compiler-Hardening-Guides
@@ -63,7 +63,7 @@ all: bin
 
 all: bin
 
-bin: lib/sqlite3.o lib/libfossil.o src/fnc.o src/fnc
+bin: lib/libfossil.o src/fnc.o src/fnc
 
 lib/sqlite3.o: lib/sqlite3.c lib/sqlite3.h
 	${CC} ${SQLITE_CFLAGS} -c $< -o $@
@@ -85,9 +85,9 @@ src/fnc: src/fnc.o src/diff.o src/error.o compat/reall
 	${CC} ${FNC_CFLAGS} -c $< -o $@
 
 src/fnc: src/fnc.o src/diff.o src/error.o compat/reallocarray.o \
-	lib/libfossil.o lib/sqlite3.o fnc.bld.mk
+	lib/libfossil.o fnc.bld.mk
 	${CC} -o $@ src/fnc.o src/diff.o src/error.o compat/reallocarray.o \
-	lib/libfossil.o lib/sqlite3.o ${FNC_LDFLAGS}
+	lib/libfossil.o ${FNC_LDFLAGS}
 
 dev:
 	${MAKE} GOHARD=1
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
