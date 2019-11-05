# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	minetest
PORTVERSION=	5.0.1
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Near-infinite-world block sandbox game

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/doc/lgpl-2.1.txt

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3 \
		libgmp.so:math/gmp

USE_GITHUB=	yes
GH_ACCOUNT=	minetest

USES=		cmake compiler:c11 iconv:wchar_t
LLD_UNSAFE=	yes
CMAKE_ARGS=	-DCUSTOM_MANDIR="${PREFIX}/man" \
		-DCUSTOM_EXAMPLE_CONF_DIR="${PREFIX}/etc"

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	CURL SOUND FREETYPE NCURSES LUAJIT \
		DOCS EXAMPLES NLS
OPTIONS_MULTI=	COMP
OPTIONS_GROUP=	DATABASE

COMP_DESC=		Software components
OPTIONS_MULTI_COMP=	CLIENT SERVER

DATABASE_DESC=		Database support
OPTIONS_GROUP_DATABASE=	PGSQL LEVELDB REDIS SPATIAL

OPTIONS_DEFAULT=	CLIENT SERVER \
			CURL SOUND FREETYPE NCURSES LUAJIT
OPTIONS_EXCLUDE_powerpc64=	LUAJIT
OPTIONS_SUB=		yes

CLIENT_DESC=		Build client
CLIENT_CMAKE_BOOL=	BUILD_CLIENT
CLIENT_LIB_DEPENDS=	libpng.so:graphics/png \
			libIrrlicht.so:x11-toolkits/irrlicht
CLIENT_USES=		gl jpeg xorg
CLIENT_USE=		GL=gl XORG=x11,xext,xxf86vm
SERVER_DESC=		Build server
SERVER_CMAKE_BOOL=	BUILD_SERVER

CURL_DESC=		Enable cURL support for fetching media
CURL_CMAKE_BOOL=	ENABLE_CURL
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
SOUND_DESC=		Enable sound
SOUND_CMAKE_BOOL=	ENABLE_SOUND
FREETYPE_DESC=		Support for TrueType fonts with unicode
FREETYPE_CMAKE_BOOL=	ENABLE_FREETYPE
FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
NCURSES_DESC=		Enable ncurses console
NCURSES_CMAKE_BOOL=	ENABLE_CURSES
NCURSES_USES=		ncurses

LUAJIT_DESC=		LuaJIT support
LUAJIT_CMAKE_BOOL=	ENABLE_LUAJIT REQUIRE_LUAJIT
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit

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

# hacky way to not bring irrlicht and X11 depends for server only
.if ! ${PORT_OPTIONS:MCLIENT} && ${PORT_OPTIONS:MSERVER}
BUILD_DEPENDS+=	${NONEXISTENT}:x11-toolkits/irrlicht:patch
IRRLICHT_INCLUDE_DIR=	`${MAKE} -C ${PORTSDIR}/x11-toolkits/irrlicht -V WRKSRC`/include
CMAKE_ARGS+=	-DIRRLICHT_INCLUDE_DIR:STRING="${IRRLICHT_INCLUDE_DIR}"
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-irrlichtdepend
.endif

post-extract:
# make sure no bundled gmp is used
	@${RM} -rf ${WRKSRC}/lib/gmp
# bundled jsoncpp is OK, see comment in cmake/Modules/FindJson.cmake
#    (not sure if it affects FreeBSD, but too lazy to investigate)
# bundled lua is OK, there's no option to use system one

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/cmake/Modules/*.cmake

.include <bsd.port.mk>
