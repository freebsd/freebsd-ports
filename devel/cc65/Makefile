# Ports collection makefile for:	cc65
# Date created:			8 May 2000
# Whom:				Tim Vanderhoek <hoek@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cc65
PORTVERSION=	2.4.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://ftp.musoftware.de/pub/uz/cc65/
#		ftp://ftp.us.musoftware.de/pub/uz/cc65/
# US musoftware mirror down; main site doesn't like fetch(1)
MASTER_SITE_SUBDIR=	hoek
WRKSRC=		${WRKDIR}/cc65-2.4.1
DISTNAME=	cc65-sources-2.4.1

MAINTAINER=	hoek@FreeBSD.org

USE_GMAKE=	yes
CFLAGS+=	-DCC65_INC=\\\"${PREFIX}/lib/cc65/include\\\" \
		-DCC65_LIB=\\\"${PREFIX}/lib/cc65/lib\\\"

DOCFILES=	doc/ar65.txt doc/ca65.txt doc/cc65.txt doc/cl65.txt doc/coding.txt \
	doc/compile.txt doc/debugging.txt doc/internal.doc doc/intro.txt \
	doc/ld65.txt doc/library.txt doc/newvers.txt doc/readme.txt BUGS \
	CREDITS announce.txt

BINFILES=	binutils/ar65/ar65 binutils/ca65/ca65 binutils/ld65/ld65 \
	cc65/cc65 cl65/cl65

CC65INCFILES= 6502.h _6525.h _6526.h _6545.h _6551.h _sid.h _vdc.h _vic.h \
	ace.h apple2.h assert.h c128.h c64.h cbm.h cbm610.h conio.h ctype.h \
	dbg.h errno.h fcntl.h iso646.h joystick.h limits.h locale.h mouse.h \
	nes.h pet.h plus4.h rs232.h setjmp.h stdarg.h stddef.h stdio.h \
	stdlib.h string.h time.h

CC65LIBFILES= apple2.lib apple2.o c128.lib c128.o c64.lib c64.o cbm610.lib \
	cbm610.o pet.lib pet.o plus4.lib plus4.o

SAMPLES=	Makefile c1541.rsp hello.c nachtm.c sieve.c

do-build:
	cd ${WRKSRC}/cc65 && ${SETENV} ${MAKE_ENV} ${GMAKE} -ef make/gcc.mak
	cd ${WRKSRC}/cc65 && ${SETENV} ${MAKE_ENV} ${GMAKE} -ef make/gcc.mak
	cd ${WRKSRC}/binutils && ${SETENV} ${MAKE_ENV} ${GMAKE} -ef make/gcc.mak
	cd ${WRKSRC}/binutils && ${SETENV} ${MAKE_ENV} ${GMAKE} -ef make/gcc.mak
	cd ${WRKSRC}/cl65 && ${SETENV} ${MAKE_ENV} ${GMAKE} -ef make/gcc.mak
	cd ${WRKSRC}/cl65 && ${SETENV} ${MAKE_ENV} ${GMAKE} -ef make/gcc.mak
	cd ${WRKSRC}/lib && ${GMAKE} all

do-install:
	${MKDIR} ${PREFIX}/share/doc/cc65
	${MKDIR} ${PREFIX}/lib/cc65/include
	${MKDIR} ${PREFIX}/lib/cc65/lib
	${MKDIR} ${PREFIX}/share/doc/cc65/samples
	${INSTALL_DATA} ${DOCFILES:S,^,${WRKSRC}/,} ${PREFIX}/share/doc/cc65
	${INSTALL_DATA} ${SAMPLES:S,^,${WRKSRC}/samples/,} \
	    ${PREFIX}/share/doc/cc65/samples
	${INSTALL_PROGRAM} ${BINFILES:S,^,${WRKSRC}/,} ${PREFIX}/bin
	${INSTALL_DATA} ${CC65INCFILES:S,^,${WRKSRC}/include/,} \
	    ${PREFIX}/lib/cc65/include
	${INSTALL_DATA} ${CC65LIBFILES:S,^,${WRKSRC}/lib/,} \
	    ${PREFIX}/lib/cc65/lib

.include <bsd.port.mk>
