# $FreeBSD$

all:

install:
	mkdir -p ${PREFIX}/bin
.if defined(INSTALL_AS_USER)
	install -c -m 0755 bin/mingwm10.dll ${PREFIX}/bin
.else
	install -c -g wheel -o root -m 0755 bin/mingwm10.dll ${PREFIX}/bin
.endif	
	mkdir -p ${PREFIX}/mingw32
	cp -R lib include ${PREFIX}/mingw32

