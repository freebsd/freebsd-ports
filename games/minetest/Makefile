# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	minetest
PORTVERSION=	0.4.9
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Infiniminer/Minecraft inspired game

LICENSE=	LGPL21

LIB_DEPENDS=	libIrrlicht.so:${PORTSDIR}/x11-toolkits/irrlicht \
		sqlite3:${PORTSDIR}/databases/sqlite3

USE_GITHUB=	yes
GH_ACCOUNT=	minetest
GH_COMMIT=	ad11a9e

USES=		cmake
CMAKE_ARGS=	-DCUSTOM_MANDIR="${PREFIX}/man" \
		-DCUSTOM_EXAMPLE_CONF_DIR="${PREFIX}/etc"

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	CLIENT SERVER CURL NLS SOUND DOCS EXAMPLES FREETYPE LEVELDB LUAJIT
OPTIONS_DEFAULT=CLIENT SERVER CURL SOUND
OPTIONS_SUB=	yes

CLIENT_DESC=	Build client
SERVER_DESC=	Build server
CURL_DESC=	Enable cURL support for fetching media
SOUND_DESC=	Enable sound
LEVELDB_DESC=	Enable LevelDB backend
FREETYPE_DESC=	Support for TrueType fonts with unicode
LUAJIT_DESC=	LuaJIT support

CLIENT_CMAKE_ON=	-DBUILD_CLIENT=1
CLIENT_CMAKE_OFF=	-DBUILD_CLIENT=0
CLIENT_LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
			libpng.so:${PORTSDIR}/graphics/png
CLIENT_USE=		GL=gl XORG=x11
SERVER_CMAKE_ON=	-DBUILD_SERVER=1
SERVER_CMAKE_OFF=	-DBUILD_SERVER=0
CURL_CMAKE_ON=		-DENABLE_CURL=1
CURL_CMAKE_OFF=		-DENABLE_CURL=0
CURL_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
NLS_CMAKE_ON=		-DENABLE_GETTEXT=1
NLS_CMAKE_OFF=		-DENABLE_GETTEXT=0
NLS_USES=		gettext
NLS_LDFLAGS=		-L${LOCALBASE}/lib
SOUND_CMAKE_ON=		-DENABLE_SOUND=1
SOUND_CMAKE_OFF=	-DENABLE_SOUND=0
LEVELDB_CMAKE_ON=	-DENABLE_LEVELDB=1
LEVELDB_CMAKE_OFF=	-DENABLE_LEVELDB=0
LEVELDB_LIB_DEPENDS=	libleveldb.so:${PORTSDIR}/databases/leveldb
FREETYPE_CMAKE_ON=	-DENABLE_FREETYPE=1
FREETYPE_CMAKE_OFF=	-DENABLE_FREETYPE=0
FREETYPE_LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:${PORTSDIR}/lang/luajit

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT} && ${PORT_OPTIONS:MSOUND}
USES+=		openal
LIB_DEPENDS+=	libvorbis.so:${PORTSDIR}/audio/libvorbis
.endif

.if ${PORT_OPTIONS:MSERVER}
USE_RC_SUBR=	${PORTNAME}
USERS=		${PORTNAME}
GROUPS=		${PORTNAME}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/cmake/Modules/*.cmake
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' \
		${WRKSRC}/src/CMakeLists.txt
.if ! ${PORT_OPTIONS:MLUAJIT}
	@${REINPLACE_CMD} -e '/find_/ s|LUA_|NO&|g' \
		${WRKSRC}/src/CMakeLists.txt
.endif

.include <bsd.port.mk>
