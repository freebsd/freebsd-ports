# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	minetest
PORTVERSION=	0.4.15
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Near-infinite-world block sandbox game

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/doc/lgpl-2.1.txt

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3 \
		libgmp.so:math/gmp

USE_GITHUB=	yes
GH_ACCOUNT=	minetest

USES=		cmake iconv:wchar_t
CMAKE_ARGS=	-DCUSTOM_MANDIR="${PREFIX}/man" \
		-DCUSTOM_EXAMPLE_CONF_DIR="${PREFIX}/etc"

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	CLIENT SERVER CURL NLS SOUND DOCS EXAMPLES FREETYPE LEVELDB REDIS LUAJIT SPATIAL PGSQL
OPTIONS_DEFAULT=CLIENT SERVER CURL SOUND FREETYPE LUAJIT
OPTIONS_SUB=	yes

CLIENT_DESC=	Build client
SERVER_DESC=	Build server
CURL_DESC=	Enable cURL support for fetching media
SOUND_DESC=	Enable sound
LEVELDB_DESC=	Enable LevelDB backend
REDIS_DESC=	Enable Redis backend
FREETYPE_DESC=	Support for TrueType fonts with unicode
LUAJIT_DESC=	LuaJIT support
SPATIAL_DESC=	Enable SpatialIndex AreaStore backend

CLIENT_CMAKE_ON=	-DBUILD_CLIENT=1
CLIENT_CMAKE_OFF=	-DBUILD_CLIENT=0
CLIENT_LIB_DEPENDS=	libpng.so:graphics/png \
			libIrrlicht.so:x11-toolkits/irrlicht
CLIENT_USES=		jpeg
CLIENT_USE=		GL=gl XORG=x11,xext
SERVER_CMAKE_BOOL=	BUILD_SERVER
CURL_CMAKE_BOOL=	ENABLE_CURL
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
NLS_CMAKE_BOOL=		ENABLE_GETTEXT
NLS_USES=		gettext
NLS_LDFLAGS=		-L${LOCALBASE}/lib
SOUND_CMAKE_BOOL=	ENABLE_SOUND
LEVELDB_CMAKE_BOOL=	ENABLE_LEVELDB
LEVELDB_LIB_DEPENDS=	libleveldb.so:databases/leveldb
REDIS_CMAKE_BOOL=	ENABLE_REDIS
REDIS_LIB_DEPENDS=	libhiredis.so:databases/hiredis
FREETYPE_CMAKE_BOOL=	ENABLE_FREETYPE
FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
LUAJIT_CMAKE_BOOL=	ENABLE_LUAJIT
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit
SPATIAL_LIB_DEPENDS=	libspatialindex.so:devel/spatialindex
SPATIAL_CMAKE_BOOL=	ENABLE_SPATIAL
PGSQL_USES=		pgsql
PGSQL_CMAKE_BOOL=	ENABLE_POSTGRESQL

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

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src_unittest_test__serialization.cpp
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/cmake/Modules/*.cmake

.include <bsd.port.mk>
