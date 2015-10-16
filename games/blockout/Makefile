# Created by: Stas Timokhin <stast@bsdportal.ru>
# $FreeBSD$

PORTNAME=	blockout
PORTVERSION=	2.5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/BlockOut%20${PORTVERSION}/ \
		http://www.stasyan.com/devel/distfiles/
DISTFILES=	bl25-src${EXTRACT_SUFX} bl25-linux-x86${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BlockOut II is an adaptation of the original Blockout DOS game

LICENSE=	GPLv2 # or later

ONLY_FOR_ARCHS=	i386 amd64

USE_SDL=	mixer sdl
USES=		gmake dos2unix
DOS2UNIX_FILES=	${WRKSRC}/ImageLib/src/gif/gif.h ${WRKSRC}/ImageLib/src/gif/gif.cpp
LIB_DEPENDS+=	libasound.so:${PORTSDIR}/audio/alsa-lib
USE_GL=		gl glu

WRKSRC=		${WRKDIR}/BL_SRC
BUILD_WRKSRC=	${WRKSRC}/BlockOut

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/BlockOut/Utils.cpp

pre-build:
	cd ${WRKSRC}/ImageLib/src && ${DO_MAKE_BUILD}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/BlockOut/blockout ${STAGEDIR}${PREFIX}/bin
	cd ${WRKDIR}/blockout && ${COPYTREE_SHARE} "images sounds" ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/README.txt  ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
