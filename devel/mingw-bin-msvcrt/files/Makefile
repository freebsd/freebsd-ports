# $FreeBSD$

all:

install:
	mkdir -p ${PREFIX}/bin
	install -c -g wheel -o root -m 0755 bin/mingwm10.dll ${PREFIX}/bin
	mkdir -p /usr/local/i386-mingw32msvc
	cp -R lib include ${PREFIX}/i386-mingw32msvc
	cd mingw32; cp -R lib include ${PREFIX}/i386-mingw32msvc
