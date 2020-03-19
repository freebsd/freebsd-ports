# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lugaru
PORTVERSION=	269
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	https://bitbucket.org/oss${PORTNAME}/${PORTNAME}/downloads/
DISTNAME=	${PORTNAME}-rev${DISTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D arcade with unique fighting system and anthropomorphic characters

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libpng.so:graphics/png \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg

USES=		cmake compiler:c++11-lang gl jpeg openal:soft pkgconfig sdl tar:bzip2 xorg
USE_GL=		gl glu
USE_SDL=	sdl
USE_XORG=	sm

LDFLAGS_i386=	-Wl,-znotext

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
	${RLN} ${STAGEDIR}${DATADIR}/Data/Textures/Lugaru.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
