# Ports collection makefile for:	cc65
# Date created:			8 May 2000
# Whom:				Tim Vanderhoek <hoek@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cc65
PORTVERSION=	2.8.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://ftp.musoftware.de/pub/uz/cc65/
# Mirror sites that were not useful at the time I updated this port:
#		http://www.acc.umu.se/~arvid/cc65_mirror/ \
#		ftp://ftp.elysium.pl/tools/crossplatform/programming/c/cc65/ \
#		http://www.funet.fi/pub/cbm/programming/cc65/
MASTER_SITE_SUBDIR=	hoek
WRKSRC=		${WRKDIR}/cc65-2.8.0
DISTNAME=	cc65-sources-2.8.0

MAINTAINER=	hoek@FreeBSD.org

USE_BZIP2=	yes
USE_GMAKE=	yes
CFLAGS+=	-DCC65_INC=\\\"${PREFIX}/lib/cc65/include\\\" \
		-DCC65_LIB=\\\"${PREFIX}/lib/cc65/lib\\\" \
		-I${WRKSRC}/src/common

# These doc files can be compiled using the textproc/sgmltools port
DOCFILES= \
	doc/BUGS doc/CREDITS doc/Makefile doc/Makefile.orig \
	doc/ar65.sgml doc/ca65.sgml doc/cc65.sgml doc/cl65.sgml \
	doc/coding.sgml doc/compile.txt doc/debugging.sgml \
	doc/dio.sgml doc/geos.sgml doc/grc.txt doc/index.sgml \
	doc/internal.txt doc/intro.sgml doc/ld65.sgml \
	doc/library.sgml doc/newvers.txt doc/readme.1st announce.txt


BINFILES= \
	src/ar65/ar65 src/ca65/ca65 src/cc65/cc65 \
	src/cl65/cl65 src/da65/da65 src/grc/grc src/ld65/ld65 src/od65/od65

BINSCRIPTS= src/ca65html/ca65html

CC65INCFILES=  \
	6502.h _6525.h _6526.h _6545.h _6551.h _antic.h _gtia.h _pbi.h _pia.h \
	_pokey.h _sid.h _vdc.h _vic.h ace.h apple2.h assert.h atari.h c128.h \
	c64.h cbm.h cbm510.h cbm610.h conio.h ctype.h dbg.h dio.h errno.h \
	fcntl.h geos.h graphics.h iso646.h joystick.h limits.h locale.h \
	mouse.h pet.h plus4.h rs232.h setjmp.h stdarg.h stddef.h stdio.h \
	stdlib.h string.h time.h zlib.h

CC65GEOSINCFILES= \
	gconst.h gdisk.h gdlgbox.h gfile.h ggraph.h gmemory.h gmenu.h \
	gprocess.h gsprite.h gstruct.h gsym.h gsys.h

CC65LIBFILES= \
	apple2.o atari.o c128.o c64.o cbm510.o cbm610.o geos.o pet.o \
	plus4.o apple2.lib atari.lib c128.lib c64.lib cbm510.lib cbm610.lib \
	geos.lib pet.lib plus4.lib

SAMPLES= Makefile README hello.c mousedemo.c nachtm.c plasma.c sieve.c

GEOSSAMPLES= \
	appfile.grc apphello1.grc apphello2.grc apprmvprot.grc \
	appyesno.grc dialog.c filesel.c geosconio.c geosconiores.res \
	grphstr.c hello1.c hello2.c inittab.c menu.c rmvprot.c yesno.c

do-build:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${GMAKE} -ef make/gcc.mak
	cd ${WRKSRC}/libsrc && ${GMAKE} all

do-install:
	${MKDIR} ${PREFIX}/share/doc/cc65
	${MKDIR} ${PREFIX}/lib/cc65/include/geos
	${MKDIR} ${PREFIX}/lib/cc65/lib
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/cc65/samples/geos
	${INSTALL_DATA} ${DOCFILES:S,^,${WRKSRC}/,} ${PREFIX}/share/doc/cc65
	${INSTALL_DATA} ${SAMPLES:S,^,${WRKSRC}/samples/,} \
	    ${PREFIX}/share/doc/cc65/samples
	${INSTALL_DATA} ${GEOSSAMPLES:S,^,${WRKSRC}/samples/geos/,} \
	    ${PREFIX}/share/doc/cc65/samples/geos
.endif
	${INSTALL_PROGRAM} ${BINFILES:S,^,${WRKSRC}/,} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${BINSCRIPTS:S,^,${WRKSRC}/,} ${PREFIX}/bin
	${INSTALL_DATA} ${CC65INCFILES:S,^,${WRKSRC}/include/,} \
	    ${PREFIX}/lib/cc65/include
	${INSTALL_DATA} ${CC65GEOSINCFILES:S,^,${WRKSRC}/include/geos/,} \
	    ${PREFIX}/lib/cc65/include/geos
	${INSTALL_DATA} ${CC65LIBFILES:S,^,${WRKSRC}/libsrc/,} \
	    ${PREFIX}/lib/cc65/lib

plist:
.for file in ${DOCFILES}
	@${ECHO_CMD} %%PORTDOCS%%share/doc/cc65/`${BASENAME} ${file}`
.endfor
.for file in ${BINFILES}
	@${ECHO_CMD} bin/`${BASENAME} ${file}`
.endfor
.for file in ${BINSCRIPTS}
	@${ECHO_CMD} bin/`${BASENAME} ${file}`
.endfor
.for file in ${CC65GEOSINCFILES}
	@${ECHO_CMD} lib/cc65/include/geos/`${BASENAME} ${file}`
.endfor
.for file in ${CC65INCFILES}
	@${ECHO_CMD} lib/cc65/include/`${BASENAME} ${file}`
.endfor
.for file in ${CC65LIBFILES}
	@${ECHO_CMD} lib/cc65/lib/`${BASENAME} ${file}`
.endfor
.for file in ${SAMPLES}
	@${ECHO_CMD} %%PORTDOCS%%share/doc/cc65/samples/`${BASENAME} ${file}`
.endfor
.for file in ${GEOSSAMPLES}
	@${ECHO_CMD} \
		%%PORTDOCS%%share/doc/cc65/samples/geos/`${BASENAME} ${file}`
.endfor
	@${ECHO_CMD} @dirrm lib/cc65/lib
	@${ECHO_CMD} @dirrm lib/cc65/include/geos
	@${ECHO_CMD} @dirrm lib/cc65/include
	@${ECHO_CMD} @dirrm lib/cc65
	@${ECHO_CMD} %%PORTDOCS%%@dirrm share/doc/cc65/samples/geos
	@${ECHO_CMD} %%PORTDOCS%%@dirrm share/doc/cc65/samples
	@${ECHO_CMD} %%PORTDOCS%%@dirrm share/doc/cc65

.include <bsd.port.mk>
