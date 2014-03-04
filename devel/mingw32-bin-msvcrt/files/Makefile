# $FreeBSD$

all:

install:
	mkdir -p ${DESTDIR}${PREFIX}/bin
.if defined(INSTALL_AS_USER)
	install -c -m 0755 bin/mingwm10.dll ${DESTDIR}${PREFIX}/bin
.else
	install -c -g wheel -o root -m 0755 bin/mingwm10.dll ${DESTDIR}${PREFIX}/bin
.endif
	mkdir -p ${DESTDIR}${PREFIX}/mingw32
	cp -R lib include ${DESTDIR}${PREFIX}/mingw32
