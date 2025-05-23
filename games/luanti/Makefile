PORTNAME=	luanti
DISTVERSION=	5.13.0
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Near-infinite-world block sandbox game
WWW=		https://www.minetest.net/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/doc/lgpl-2.1.txt

LIB_DEPENDS=	libgmp.so:math/gmp \
		libjsoncpp.so:devel/jsoncpp \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++17-lang cpe iconv:wchar_t sdl ssl sqlite
GH_ACCOUNT=	luanti-org
GH_PROJECT=	luanti
USE_GITHUB=	yes
USE_SDL=	sdl2
CMAKE_ARGS=	-DCUSTOM_EXAMPLE_CONF_DIR="${PREFIX}/etc" \
CMAKE_ON=	ENABLE_SYSTEM_JSONCPP
CMAKE_OFF=	BUILD_DOCUMENTATION

TEST_ENV=	${MAKE_ENV} LC_ALL=C.UTF-8

LDFLAGS_i386=	-Wl,-znotext

DATADIR=	${PREFIX}/share/luanti

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	CURL SOUND NCURSES LUAJIT TEST \
		DOCS EXAMPLES NLS
OPTIONS_MULTI=	COMP
OPTIONS_GROUP=	DATABASE
OPTIONS_MULTI_COMP=	CLIENT SERVER
OPTIONS_GROUP_DATABASE=	PGSQL LEVELDB REDIS SPATIAL
OPTIONS_DEFAULT=	CLIENT SERVER \
			CURL SOUND NCURSES LUAJIT
OPTIONS_SUB=		yes

COMP_DESC=		Software components
DATABASE_DESC=		Database support

CLIENT_DESC=		Build client
CLIENT_CMAKE_BOOL=	BUILD_CLIENT
CLIENT_LIB_DEPENDS=	libpng.so:graphics/png \
			libfreetype.so:print/freetype2
CLIENT_USES=		gl jpeg xorg
CLIENT_USE=		GL=gl XORG=x11,xext,xi
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
LUAJIT_USES=		luajit:luajit-openresty

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

TEST_CMAKE_BOOL=	BUILD_UNITTESTS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT} && ${PORT_OPTIONS:MSOUND}
USES+=		openal
LIB_DEPENDS+=	libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg
.endif

.if ${PORT_OPTIONS:MSERVER}
USE_RC_SUBR=	minetest
USERS=		minetest
GROUPS=		minetest
.endif

post-extract:
# make sure no bundled gmp is used
	@${RM} -rf ${WRKSRC}/lib/gmp ${WRKSRC}/lib/jsoncpp
# bundled lua is OK, there's no option to use system one

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/cmake/Modules/*.cmake

do-test-TEST-on:
.if ${PORT_OPTIONS:MCLIENT}
	cd ${WRKDIR} && ${SETENV} ${TEST_ENV} ${STAGEDIR}${PREFIX}/bin/luanti --run-unittests
.endif
.if ${PORT_OPTIONS:MSERVER}
	cd ${WRKDIR} && ${SETENV} ${TEST_ENV} ${STAGEDIR}${PREFIX}/bin/luantiserver --run-unittests
.endif

.include <bsd.port.mk>
