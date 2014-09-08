# $FreeBSD$

all: stubify

stubify:
	cc -O src/stub/stubify.c -o stubify

install:
	mkdir -p $(DESTDIR)${PREFIX}/i586-pc-msdosdjgpp/bin
	$(BSD_INSTALL_PROGRAM) stubify $(DESTDIR)${PREFIX}/i586-pc-msdosdjgpp/bin
	cp -R lib include $(DESTDIR)${PREFIX}/i586-pc-msdosdjgpp

