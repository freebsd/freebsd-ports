# $FreeBSD$

all:

install:
	mkdir -p ${PREFIX}/bin
	install -c -g wheel -o root -m 0755 bin/mingwm10.dll ${PREFIX}/bin
	mkdir -p ${PREFIX}/mingw32
	cp -R lib include ${PREFIX}/mingw32

