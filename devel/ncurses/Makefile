# New ports collection makefile for:	ncurses
# Version required:			4.2
# Date created:				23 September 1997
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.5 1998/07/03 23:14:14 steve Exp $
#

DISTNAME=		ncurses-4.2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU} \
			ftp://ftp.clark.net/pub/dickey/ncurses/

MAINTAINER=		andy@icc.surw.chel.su

MANUAL_PACKAGE_BUILD=	conflicts with system ncurses
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/misc --disable-overwrite \
		--disable-termcap --includedir=${PREFIX}/include/ncurses \
		--prefix=${PREFIX} --with-profile --with-shared --with-debug
CONFIGURE_ENV=		gnat_exists="no"

post-install:
	@ ${MKDIR} ${PREFIX}/share/doc/ncurses
.for file in ANNOUNCE INSTALL NEWS README TO-DO announce.html misc/hackguide.doc misc/hackguide.html misc/ncurses-intro.doc misc/ncurses-intro.html
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/ncurses
.endfor
	@ ${INSTALL_DATA} ${WRKSRC}/misc/terminfo.src ${PREFIX}/share/misc/terminfo
	@ ${MKDIR} ${PREFIX}/share/examples/ncurses
.for file in README blue.c bs.6 bs.c firework.c gdc.6 gdc.c hanoi.c hashtest.c knight.c lrtest.c ncurses.c newdemo.c rain.c tclock.c test.priv.h testcurs.c view.c worm.c xmas.c
	@ ${INSTALL_DATA} ${WRKSRC}/test/${file} ${PREFIX}/share/examples/ncurses
.endfor
	@ ${INSTALL_SCRIPT} ${WRKSRC}/test/tracemunch ${PREFIX}/share/examples/ncurses
	@ ${INSTALL_DATA} ${FILESDIR}/Makefile ${PREFIX}/share/examples/ncurses
	@ ${MKDIR} ${PREFIX}/share/examples/ncurses/c++
.for file in NEWS PROBLEMS README-first cursesp.cc cursesp.h cursesw.cc cursesw.h demo.cc
	@ ${INSTALL_DATA} ${WRKSRC}/c++/${file} ${PREFIX}/share/examples/ncurses/c++
.endfor
	@ ${INSTALL_DATA} ${FILESDIR}/Makefile.c++ ${PREFIX}/share/examples/ncurses/c++/Makefile

.include <bsd.port.mk>
