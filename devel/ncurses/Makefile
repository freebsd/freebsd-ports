# New ports collection makefile for:	ncurses
# Version required:			1.9.9g
# Date created:				23 September 1997
# Whom:					Andrey Zakhvatov
#
# $Id$
#

DISTNAME=		ncurses-1.9.9g
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.netcom.com/pub/zm/zmbenhal/ncurses/

MAINTAINER=		andy@icc.surw.chel.su

WRKSRC=			${WRKDIR}/ncurses_1.9.9g
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-shared --datadir=${PREFIX}/share/misc
USE_GMAKE=		yes
MAKE_FLAGS+=		ABI_VERSION=3.4 -f

post-install:
	@ ${MKDIR} ${PREFIX}/include/ncurses
.for file in curses eti form menu panel term termcap unctrl
	@ ${MV} ${PREFIX}/include/${file}.h ${PREFIX}/include/ncurses
.endfor
	@ ${MKDIR} ${PREFIX}/share/doc/ncurses
.for file in ANNOUNCE INSTALL NEWS README TO-DO announce.html misc/hackguide.doc misc/hackguide.html misc/ncurses-intro.doc misc/ncurses-intro.html
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/ncurses
.endfor
	@ ${INSTALL_DATA} ${WRKSRC}/misc/terminfo.src ${PREFIX}/share/misc/terminfo
	@ ${MKDIR} ${PREFIX}/share/examples/ncurses
.for file in README blue.c bs.6 bs.c firework.c gdc.6 gdc.c hanoi.c hashtest.c knight.c lrtest.c ncurses.c newdemo.c rain.c tclock.c test.priv.h testcurs.c view.c worm.c xmas.c
	@ ${INSTALL_DATA} ${WRKSRC}/test/${file} ${PREFIX}/share/examples/ncurses
.endfor
	@ ${MKDIR} ${PREFIX}/share/examples/ncurses/include
	@ ${INSTALL_DATA} ${WRKSRC}/include/config.h ${PREFIX}/share/examples/ncurses/include
	@ ${INSTALL_SCRIPT} ${WRKSRC}/test/tracemunch ${PREFIX}/share/examples/ncurses
	@ ${INSTALL_DATA} ${FILESDIR}/Makefile ${PREFIX}/share/examples/ncurses
	@ ${MKDIR} ${PREFIX}/share/examples/ncurses/c++
.for file in README-first cursesp.cc cursesp.h cursesw.cc cursesw.h demo.cc
	@ ${INSTALL_DATA} ${WRKSRC}/c++/${file} ${PREFIX}/share/examples/ncurses/c++
.endfor
	@ ${INSTALL_DATA} ${FILESDIR}/Makefile.c++ ${PREFIX}/share/examples/ncurses/c++/Makefile

.include <bsd.port.mk>
