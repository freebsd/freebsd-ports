# New ports collection makefile for:	demonquake
# Date created:				13 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	demonquake
PORTVERSION=	0.16
CATEGORIES=	games
MASTER_SITES=	http://qudos.quakedev.com/linux/quake1/
DISTNAME=	DemonQuake-v${PORTVERSION}-bin-src.linux
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		DemonQuake-data${EXTRACT_SUFX}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Another improved Quake engine based on FuhQuake

LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
USE_GL=		yes
USE_BZIP2=	yes

OPTIONS=	OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		SDL "Build SDL client" on

ALL_TARGET=	release

PLIST_FILES=	bin/${PORTNAME} \
		%%Q1DIR%%/${PORTNAME}/pak0.pak
PLIST_DIRS=	%%Q1DIR%%/${PORTNAME}

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
MAKE_ENV+=	WITH_OPTIMIZED_CFLAGS=YES
.endif

.if !defined(WITHOUT_SDL)
USE_SDL=	sdl
MAKE_ENV+=	BUILD_SDL=YES
PLIST_FILES+=	bin/${PORTNAME}-sdl
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/release/${PORTNAME} ${PREFIX}/bin
.if !defined(WITHOUT_SDL)
	${INSTALL_PROGRAM} ${WRKSRC}/release/${PORTNAME}-sdl ${PREFIX}/bin
.endif
	${MKDIR} ${Q1DIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/DemonQuake-data/${PORTNAME}/pak0.pak \
		${Q1DIR}/${PORTNAME}

.include <bsd.port.post.mk>
