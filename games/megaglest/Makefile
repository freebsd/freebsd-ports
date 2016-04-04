# Created by: Sven Moeller <smoeller@nichthelfer.de>
# $FreeBSD$

PORTNAME=	megaglest
PORTVERSION=	3.11.1
CATEGORIES=	games
DISTNAME=	${PORTNAME}-source-${PORTVERSION}

MAINTAINER=	monwarez@mailoo.org
COMMENT=	Open source 3D real-time strategy game

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/docs/gnu_gpl_3.0.txt

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpng.so:graphics/png \
		libxerces-c.so:textproc/xerces-c3 \
		libftgl.so:graphics/ftgl \
		libvorbis.so:audio/libvorbis
BUILD_DEPENDS=	${LOCALBASE}/include/libircclient.h:irc/libircclient \
		${LOCALBASE}/include/miniupnpc/miniupnpc.h:net/miniupnpc
RUN_DEPENDS=	${DATADIR}/tutorials/2_basic_tutorial/2_basic_tutorial.xml:games/megaglest-data

USE_GITHUB=	yes
GH_ACCOUNT=	MegaGlest
GH_PROJECT=	megaglest-source

SUB_FILES=	pkg-message

USES=		cmake compiler:c++11-lib display:build dos2unix jpeg lua \
		openal:al,alut pkgconfig tar:xz
USE_GL=		glew gl glu
USE_SDL=	yes
USE_WX=		3.0
USE_CXXSTD=	c++11

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lssl -lcrypto

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
	${INSTALL_DATA} ${WRKSRC}/mk/linux/megaglest.desktop ${STAGEDIR}${PREFIX}/share/applications/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons
	${INSTALL_DATA} ${WRKSRC}/mk/linux/megaglest.png ${STAGEDIR}${PREFIX}/share/icons/
	${INSTALL_PROGRAM} ${WRKSRC}/source/glest_game/megaglest ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.for f in mk/linux/glest.ini mk/shared/glestkeys.ini mk/shared/servers.ini
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
. for f in docs/AUTHORS.source_code.txt docs/CHANGELOG.txt docs/README.txt docs/COPYRIGHT.source_code.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
. endfor
.endif
.if ${PORT_OPTIONS:MEDITOR}
	${INSTALL_PROGRAM} ${WRKSRC}/source/glest_map_editor/megaglest_editor ${STAGEDIR}${PREFIX}/bin/megaglest_editor
.endif

.include <bsd.port.mk>
