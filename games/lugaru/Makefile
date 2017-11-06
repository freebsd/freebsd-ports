# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lugaru
PORTVERSION=	269
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	https://bitbucket.org/oss${PORTNAME}/${PORTNAME}/downloads/
DISTNAME=	${PORTNAME}-rev${DISTVERSION}-src

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	3D arcade with unique fighting system and anthropomorphic characters

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libpng.so:graphics/png \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg

USES=		cmake jpeg openal:soft pkgconfig tar:bzip2
USE_GL=		glu
USE_SDL=	sdl
USE_XORG=	sm
USE_GCC=	yes

PORTDOCS=	README
OPTIONS_DEFINE=	DOCS

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Lugaru" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ActionGame;" ""

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/lugaru|${DATADIR}|' \
		${WRKSRC}/CMakeLists.txt

post-install:
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${LN} -sf ${DATADIR}/Data/Textures/Lugaru.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
