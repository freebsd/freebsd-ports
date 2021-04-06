all:

install:
	mkdir -p ${DESTDIR}${PREFIX}/bin
	install -c -m 0755 bin/mingwm10.dll ${DESTDIR}${PREFIX}/bin
	mkdir -p ${DESTDIR}${PREFIX}/mingw32
	cp -R lib include ${DESTDIR}${PREFIX}/mingw32
