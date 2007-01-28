# $FreeBSD$

all: stubify

stubify:
	cc -O src/stub/stubify.c -o stubify

install:
	mkdir -p ${PREFIX}/i586-pc-msdosdjgpp/bin
	install -c -g wheel -o root -m 0755 stubify ${PREFIX}/i586-pc-msdosdjgpp/bin
	cp -R lib include ${PREFIX}/i586-pc-msdosdjgpp

