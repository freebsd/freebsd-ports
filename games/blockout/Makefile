# Created by: Stas Timokhin <stast@bsdportal.ru>
# $FreeBSD$

PORTNAME=	blockout
PORTVERSION=	2.5
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/BlockOut%20${PORTVERSION}/ \
		http://www.stasyan.com/devel/distfiles/
DISTFILES=	bl25-src${EXTRACT_SUFX} bl25-linux-x86${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BlockOut II is an adaptation of the original Blockout DOS game

LICENSE=	GPLv2+

ONLY_FOR_ARCHS=	i386 amd64

USES=		dos2unix gl gmake sdl
USE_SDL=	mixer sdl
DOS2UNIX_FILES=	ImageLib/src/gif/gif.h \
		ImageLib/src/gif/gif.cpp BlockOut/*.cpp \
		ImageLib/src/png/hpng.c
USE_GL=		gl glu

WRKSRC=		${WRKDIR}/BL_SRC
BUILD_WRKSRC=	${WRKSRC}/BlockOut

OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="BlockOut" \
		"" \
		"${PREFIX}/share/pixmaps/block_icon.ico" \
		"${PORTNAME}" \
		"" \
		""

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/BlockOut/Utils.cpp

pre-build:
	cd ${WRKSRC}/ImageLib/src && ${DO_MAKE_BUILD}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/BlockOut/blockout ${STAGEDIR}${PREFIX}/bin
	cd ${WRKDIR}/blockout && ${COPYTREE_SHARE} "images sounds" ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/BlockOut/block_icon.ico ${STAGEDIR}${PREFIX}/share/pixmaps

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/README.txt  ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
