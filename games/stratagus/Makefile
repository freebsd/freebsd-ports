# Created by: Travis Poppe <tlp@liquidx.org>
# $FreeBSD$

PORTNAME=	stratagus
PORTVERSION=	2.2.7
CATEGORIES=	games
MASTER_SITES=	http://launchpadlibrarian.net/113005346/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free cross-platform real-time strategy gaming engine

LICENSE=	GPLv2

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

OPTIONS_DEFINE=	MIKMOD MNG THEORA VORBIS DOCS
OPTIONS_DEFAULT=	VORBIS

USE_GL=		glu
USE_SDL=	sdl
USE_SQLITE=	3
USE_LUA=	5.0+
LUA_COMPS=	toluaxx
USES=		cmake:outsource pkgconfig
CMAKE_ARGS=	-DGAMEDIR:STRING="bin" \
		-DTOLUA++_APP:STRING="${TOLUAXX_CMD}" \
		-DTOLUA++_INCLUDE_DIR:STRING="${LUA_INCDIR}" \
		-DTOLUA++_LIBRARY:STRING="${LUA_LIBDIR}/libtolua++.so"

PORTDOCS=	*
PLIST_FILES=	bin/png2stratagus bin/stratagus sbin/metaserver \
		man/man6/stratagus.6.gz

MIKMOD_LIB_DEPENDS=	libmikmod.so:${PORTSDIR}/audio/libmikmod
MIKMOD_CMAKE_ON=	-DWITH_MIKMOD:BOOL=ON
MIKMOD_CMAKE_OFF=	-DWITH_MIKMOD:BOOL=OFF

MNG_LIB_DEPENDS=	libmng.so:${PORTSDIR}/graphics/libmng
MNG_CMAKE_ON=		-DWITH_MNG:BOOL=ON
MNG_CMAKE_OFF=		-DWITH_MNG:BOOL=OFF

THEORA_LIB_DEPENDS=	libtheora.so:${PORTSDIR}/multimedia/libtheora
THEORA_CMAKE_ON=	-DWITH_THEORA:BOOL=ON
THEORA_CMAKE_OFF=	-DWITH_THEORA:BOOL=OFF

VORBIS_LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis
VORBIS_CMAKE_ON=	-DWITH_OGGVORBIS:BOOL=ON
VORBIS_CMAKE_OFF=	-DWITH_OGGVORBIS:BOOL=OFF

post-install:
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} stratagus.6 ${STAGEDIR}${MAN6PREFIX}/man/man6)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} [a-z]*.html *.txt ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/graphics
	(cd ${WRKSRC}/doc/graphics && ${INSTALL_DATA} * ${STAGEDIR}${DOCSDIR}/graphics)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/scripts
	(cd ${WRKSRC}/doc/scripts && ${INSTALL_DATA} * ${STAGEDIR}${DOCSDIR}/scripts)

.include <bsd.port.mk>
