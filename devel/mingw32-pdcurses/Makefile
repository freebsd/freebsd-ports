# New ports collection makefile for:	mingw32-pdcurses
# Date created:				28 April 2006
# Whom:					Ed Schouten <ed@fxq.nl>
#
# $FreeBSD$
#

PORTNAME=	pdcurses
PORTVERSION=	2.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	mingw32-
DISTNAME=	PDCurses-${PORTVERSION}

MAINTAINER=	ed@fxq.nl
COMMENT=	Curses and Panel terminal library for Windows

BUILD_DEPENDS=	${PKGNAMEPREFIX}gcc:${PORTSDIR}/devel/${PKGNAMEPREFIX}gcc \
		mingwm10.dll:${PORTSDIR}/devel/mingw32-bin-msvcrt

USE_GMAKE=	yes

PDCURSES_LIBS=	pdcurses.a panel.a

do-build:
	@${GMAKE} -C ${WRKSRC}/win32 -f gccwin32.mak PDCURSES_SRCDIR=.. \
		CC=${PKGNAMEPREFIX}gcc LIBEXE=${PKGNAMEPREFIX}ar \
		SHELL=${SH} ${PDCURSES_LIBS}

do-install:
.for f in curses.h curspriv.h panel.h term.h
	${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/mingw32/include/$f
.endfor

.for f in ${PDCURSES_LIBS}
	${INSTALL_DATA} ${WRKSRC}/win32/$f ${PREFIX}/mingw32/lib/lib$f
.endfor
	${LN} -sf libpdcurses.a ${PREFIX}/mingw32/lib/libcurses.a

.include <bsd.port.mk>
