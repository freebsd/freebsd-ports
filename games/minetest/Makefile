PORTNAME=	minetest
PORTVERSION=	5.5.0
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Near-infinite-world block sandbox game

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/doc/lgpl-2.1.txt

LIB_DEPENDS=	libgmp.so:math/gmp \
		libjsoncpp.so:devel/jsoncpp \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c11 cpe iconv:wchar_t sqlite
USE_GITHUB=	yes
GH_TUPLE=	minetest:irrlicht:d3132e0:irrlicht/lib/irrlichtmt

CMAKE_ARGS=	-DCUSTOM_MANDIR="${PREFIX}/man" \
		-DCUSTOM_EXAMPLE_CONF_DIR="${PREFIX}/etc" \
		-DENABLE_SYSTEM_JSONCPP=ON

LDFLAGS_i386=	-Wl,-znotext

PORTSCOUT=	skipv:5.4.2-android

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	CURL SOUND NCURSES LUAJIT \
		DOCS EXAMPLES NLS
OPTIONS_MULTI=	COMP
OPTIONS_GROUP=	DATABASE

COMP_DESC=		Software components
OPTIONS_MULTI_COMP=	CLIENT SERVER

DATABASE_DESC=		Database support
OPTIONS_GROUP_DATABASE=	PGSQL LEVELDB REDIS SPATIAL

OPTIONS_DEFAULT=	CLIENT SERVER \
			CURL SOUND NCURSES LUAJIT
OPTIONS_SUB=		yes

CLIENT_DESC=		Build client
CLIENT_CMAKE_BOOL=	BUILD_CLIENT
CLIENT_LIB_DEPENDS=	libpng.so:graphics/png \
			libfreetype.so:print/freetype2
CLIENT_USES=		gl jpeg xorg
CLIENT_USE=		GL=gl XORG=x11,xext,xxf86vm
SERVER_DESC=		Build server
SERVER_CMAKE_BOOL=	BUILD_SERVER

CURL_DESC=		Enable cURL support for fetching media
CURL_CMAKE_BOOL=	ENABLE_CURL
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
SOUND_DESC=		Enable sound
SOUND_CMAKE_BOOL=	ENABLE_SOUND
NCURSES_DESC=		Enable ncurses console
NCURSES_CMAKE_BOOL=	ENABLE_CURSES
NCURSES_USES=		ncurses

LUAJIT_DESC=		LuaJIT support
LUAJIT_CMAKE_BOOL=	ENABLE_LUAJIT REQUIRE_LUAJIT
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit-openresty

PGSQL_USES=		pgsql
PGSQL_CMAKE_BOOL=	ENABLE_POSTGRESQL
LEVELDB_DESC=		Enable LevelDB backend
LEVELDB_CMAKE_BOOL=	ENABLE_LEVELDB
LEVELDB_LIB_DEPENDS=	libleveldb.so:databases/leveldb
REDIS_DESC=		Enable Redis backend
REDIS_CMAKE_BOOL=	ENABLE_REDIS
REDIS_LIB_DEPENDS=	libhiredis.so:databases/hiredis
SPATIAL_DESC=		Enable SpatialIndex AreaStore backend
SPATIAL_LIB_DEPENDS=	libspatialindex.so:devel/spatialindex
SPATIAL_CMAKE_BOOL=	ENABLE_SPATIAL

NLS_CMAKE_BOOL=		ENABLE_GETTEXT
NLS_USES=		gettext
NLS_LDFLAGS=		-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT} && ${PORT_OPTIONS:MSOUND}
USES+=		openal
LIB_DEPENDS+=	libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg
.endif

.if ${PORT_OPTIONS:MSERVER}
USE_RC_SUBR=	${PORTNAME}
USERS=		${PORTNAME}
GROUPS=		${PORTNAME}
.endif

post-extract:
# make sure no bundled gmp is used
	@${RM} -rf ${WRKSRC}/lib/gmp ${WRKSRC}/lib/jsoncpp
# bundled lua is OK, there's no option to use system one

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/cmake/Modules/*.cmake

.include <bsd.port.mk>
