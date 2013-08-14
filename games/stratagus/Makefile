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

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

OPTIONS_DEFINE=	MIKMOD MNG THEORA VORBIS DOCS
OPTIONS_DEFAULT=	VORBIS

USE_GL=		glu
USE_SDL=	sdl
USE_SQLITE=	3
USE_LUA=	5.0+
LUA_COMPS=	toluaxx
USES=		cmake:outsource
CMAKE_ARGS=	-DGAMEDIR:STRING="bin" \
		-DTOLUA++_APP:STRING="${TOLUAXX_CMD}" \
		-DTOLUA++_INCLUDE_DIR:STRING="${LUA_INCDIR}" \
		-DTOLUA++_LIBRARY:STRING="${LUA_LIBDIR}/libtolua++.so"

MAN6=		stratagus.6
PORTDOCS=	*
PLIST_FILES=	bin/png2stratagus bin/stratagus sbin/metaserver

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMIKMOD}
LIB_DEPENDS+=	mikmod:${PORTSDIR}/audio/libmikmod
CMAKE_ARGS+=	-DWITH_MIKMOD:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_MIKMOD:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MMNG}
LIB_DEPENDS+=	mng:${PORTSDIR}/graphics/libmng
CMAKE_ARGS+=	-DWITH_MNG:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_MNG:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MTHEORA}
LIB_DEPENDS+=	theora:${PORTSDIR}/multimedia/libtheora
CMAKE_ARGS+=	-DWITH_THEORA:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_THEORA:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
CMAKE_ARGS+=	-DWITH_OGGVORBIS:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_OGGVORBIS:BOOL=OFF
.endif

post-install:
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} stratagus.6 ${MAN6PREFIX}/man/man6)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} [a-z]*.html *.txt ${DOCSDIR})
	@${MKDIR} ${DOCSDIR}/graphics
	(cd ${WRKSRC}/doc/graphics && ${INSTALL_DATA} * ${DOCSDIR}/graphics)
	@${MKDIR} ${DOCSDIR}/scripts
	(cd ${WRKSRC}/doc/scripts && ${INSTALL_DATA} * ${DOCSDIR}/scripts)
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}
.endif

.include <bsd.port.mk>
