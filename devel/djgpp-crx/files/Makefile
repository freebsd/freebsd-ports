# $FreeBSD$

all: stubify

stubify:
	cc -O src/stub/stubify.c -o stubify

install:
	mkdir -p $(DESTDIR)${PREFIX}/i586-pc-msdosdjgpp/bin
	install -c -g wheel -o root -m 0755 stubify $(DESTDIR)${PREFIX}/i586-pc-msdosdjgpp/bin
	cp -R lib include $(DESTDIR)${PREFIX}/i586-pc-msdosdjgpp

