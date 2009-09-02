# New ports collection makefile for:	mingw32-pdcurses
# Date created:				28 April 2006
# Whom:					Ed Schouten <ed@fxq.nl>
#
# $FreeBSD$
#

PORTNAME=	pdcurses
PORTVERSION=	3.4
CATEGORIES=	devel
MASTER_SITES=	SF
PKGNAMEPREFIX=	mingw32-
DISTNAME=	PDCurses-${PORTVERSION}

MAINTAINER=	ed@FreeBSD.org
COMMENT=	Curses and Panel terminal library for Windows

BUILD_DEPENDS=	${PKGNAMEPREFIX}gcc:${PORTSDIR}/devel/${PKGNAMEPREFIX}gcc \
		mingwm10.dll:${PORTSDIR}/devel/mingw32-bin-msvcrt

USE_GMAKE=	yes
MAKEFILE=	gccwin32.mak
WRKSRC=		${WRKDIR}/${DISTNAME}/win32
MAKE_ARGS+=	CC=${PKGNAMEPREFIX}gcc LIBEXE=${PKGNAMEPREFIX}ar
ALL_TARGET=	pdcurses.a

do-install:
.for f in curses.h curspriv.h panel.h term.h
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/$f ${PREFIX}/mingw32/include/$f
.endfor
	${INSTALL_DATA} ${WRKSRC}/pdcurses.a ${PREFIX}/mingw32/lib/libpdcurses.a
	${LN} -sf libpdcurses.a ${PREFIX}/mingw32/lib/libcurses.a
	${LN} -sf libpdcurses.a ${PREFIX}/mingw32/lib/libpanel.a

.include <bsd.port.mk>
