# New ports collection makefile for:	demonquake
# Date created:				13 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	demonquake
PORTVERSION=	0.16.1
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://qudos.quakedev.com/linux/quake1/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		DemonQuake-data${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another improved Quake engine based on FuhQuake

LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
USE_DOS2UNIX=	yes
USE_GL=		gl
USE_XORG=	xpm xxf86dga
USE_BZIP2=	yes

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS
OPTIONS_MULTI=	CLIENT
OPTIONS_MULTI_CLIENT=	OPENGL SDL
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS OPENGL SDL

ALL_TARGET=	release

PLIST_FILES=	%%Q1DIR%%/${PORTNAME}/pak0.pak
PLIST_DIRS=	%%Q1DIR%%/${PORTNAME}

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENGL}
MAKE_ENV+=	BUILD_DEMONQUAKE=YES
PLIST_FILES+=	bin/${PORTNAME}-glx
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
MAKE_ENV+=	OPTIMIZE=YES
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	sdl
MAKE_ENV+=	BUILD_DEMONQUAKE_SDL=YES
PLIST_FILES+=	bin/${PORTNAME}-sdl
.endif

do-install:
.if ${PORT_OPTIONS:MOPENGL}
	${INSTALL_PROGRAM} ${WRKSRC}/quake/${PORTNAME}-glx ${PREFIX}/bin
.endif
.if ${PORT_OPTIONS:MSDL}
	${INSTALL_PROGRAM} ${WRKSRC}/quake/${PORTNAME}-sdl ${PREFIX}/bin
.endif
	${MKDIR} ${Q1DIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/DemonQuake-data/${PORTNAME}/pak0.pak \
		${Q1DIR}/${PORTNAME}

.include <bsd.port.mk>
