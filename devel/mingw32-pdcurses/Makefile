# Created by: Ed Schouten <ed@fxq.nl>
# $FreeBSD$

PORTNAME=	pdcurses
PORTVERSION=	3.4
CATEGORIES=	devel
MASTER_SITES=	SF
PKGNAMEPREFIX=	mingw32-
DISTNAME=	PDCurses-${PORTVERSION}

MAINTAINER= ports@FreeBSD.org
COMMENT=	Curses and Panel terminal library for Windows

BUILD_DEPENDS=	${PKGNAMEPREFIX}gcc:devel/${PKGNAMEPREFIX}gcc \
		mingwm10.dll:devel/mingw32-bin-msvcrt

USES=		gmake
MAKEFILE=	gccwin32.mak
WRKSRC=		${WRKDIR}/${DISTNAME}/win32
MAKE_ARGS+=	CC=${PKGNAMEPREFIX}gcc LIBEXE=${PKGNAMEPREFIX}ar
ALL_TARGET=	pdcurses.a

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/mingw32/include
	@${MKDIR} ${STAGEDIR}${PREFIX}/mingw32/lib
.for f in curses.h curspriv.h panel.h term.h
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/$f ${STAGEDIR}${PREFIX}/mingw32/include/$f
.endfor
	${INSTALL_DATA} ${WRKSRC}/pdcurses.a ${STAGEDIR}${PREFIX}/mingw32/lib/libpdcurses.a
	${LN} -sf libpdcurses.a ${STAGEDIR}${PREFIX}/mingw32/lib/libcurses.a
	${LN} -sf libpdcurses.a ${STAGEDIR}${PREFIX}/mingw32/lib/libpanel.a

.include <bsd.port.mk>
