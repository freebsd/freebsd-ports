# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lugaru
PORTVERSION=	269
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-rev${DISTVERSION}-src

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	3D arcade with unique fighting system and anthropomorphic characters

LICENSE=	GPLv2

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libogg.so:${PORTSDIR}/audio/libogg

USE_BZIP2=	yes
USES=		cmake openal:soft pkgconfig
USE_GL=		glu
USE_SDL=	sdl
USE_XORG=	sm
USE_GCC=	yes

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Lugaru" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ActionGame;" false

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/lugaru|${DATADIR}|' \
		${WRKSRC}/CMakeLists.txt

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${LN} -sf ${DATADIR}/Data/Textures/Lugaru.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
