# Created by: Sven Moeller <smoeller@nichthelfer.de>
# $FreeBSD$

PORTNAME=	megaglest
PORTVERSION=	3.9.0.4
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}_3.9.0/
DISTNAME=	${PORTNAME}-source-${PORTVERSION}

MAINTAINER=	rnejdl@ringofsaturn.com
COMMENT=	Open source 3D real-time strategy game

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libpng.so:${PORTSDIR}/graphics/png \
		libxerces-c.so:${PORTSDIR}/textproc/xerces-c3 \
		libftgl.so:${PORTSDIR}/graphics/ftgl \
		libvorbis.so:${PORTSDIR}/audio/libvorbis
BUILD_DEPENDS=	${LOCALBASE}/include/libircclient.h:${PORTSDIR}/irc/libircclient \
		${LOCALBASE}/include/miniupnpc/miniupnpc.h:${PORTSDIR}/net/miniupnpc
RUN_DEPENDS=	${DATADIR}/tutorials/2_basic_tutorial/2_basic_tutorial.xml:${PORTSDIR}/games/megaglest-data

SUB_FILES=	pkg-message

USES=		cmake compiler:c++11-lib display:build dos2unix jpeg lua \
		openal:al,alut pkgconfig tar:xz
USE_GL=		glew gl glu
USE_SDL=	yes
USE_WX=		3.0
USE_CXXSTD=	c++11
WX_UNICODE=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lssl -lcrypto
WRKSRC=		${WRKDIR}/${PORTNAME}-3.9.0

OPTIONS_DEFINE=	EDITOR DOCS
OPTIONS_SUB=	yes
EDITOR_DESC=	Install MegaGlest Editor

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local/include/lua51,${LUA_INCDIR},g ; \
		s,/usr/local/lib/lua51,${LUA_LIBDIR},g ; \
		s,lua5.2,lua-${LUA_VER},g' \
		${WRKSRC}/mk/cmake/Modules/FindLUA.cmake

do-install:
	${STRIP_CMD} ${WRKSRC}/source/glest_game/megaglest
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/source/glest_game/megaglest ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.for f in glest.ini glestkeys.ini servers.ini
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
. for f in AUTHORS.source_code.txt CHANGELOG.txt README.txt COPYRIGHT.source_code.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
. endfor
.endif
.if ${PORT_OPTIONS:MEDITOR}
	${INSTALL_PROGRAM} ${WRKSRC}/source/glest_map_editor/megaglest_editor ${STAGEDIR}${PREFIX}/bin/megaglest_editor
.endif

.include <bsd.port.mk>
