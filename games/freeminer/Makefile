# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freeminer
PORTVERSION=	0.4.10.4
PORTREVISION=	7
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open source sandbox game inspired by Minecraft

LICENSE=	LGPL21+ GPLv3+ # source mentions GPLv3+, LICENSE.txt LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING # don't remove space

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

USE_GITHUB=	yes

USES=		compiler:c++11-lib cmake
LLD_UNSAFE=	yes
CMAKE_ARGS=	-DCUSTOM_MANDIR="${PREFIX}/man" \
		-DCUSTOM_EXAMPLE_CONF_DIR="${PREFIX}/etc" \
		-DRUN_IN_PLACE=0

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	CLIENT SERVER CURL SOUND FREETYPE LEVELDB LUAJIT NLS DOCS EXAMPLES
OPTIONS_DEFAULT=CLIENT SERVER CURL SOUND FREETYPE LEVELDB LUAJIT
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
CLIENT_LIB_DEPENDS=	libpng.so:graphics/png \
			libIrrlicht.so:x11-toolkits/irrlicht
CLIENT_USES=		jpeg
CLIENT_USE=		GL=gl XORG=x11
SERVER_CMAKE_ON=	-DBUILD_SERVER=1
SERVER_CMAKE_OFF=	-DBUILD_SERVER=0
CURL_CMAKE_ON=		-DENABLE_CURL=1
CURL_CMAKE_OFF=		-DENABLE_CURL=0
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
NLS_CMAKE_ON=		-DENABLE_GETTEXT=1
NLS_CMAKE_OFF=		-DENABLE_GETTEXT=0
NLS_USES=		gettext
NLS_LDFLAGS=		-L${LOCALBASE}/lib
SOUND_CMAKE_ON=		-DENABLE_SOUND=1
SOUND_CMAKE_OFF=	-DENABLE_SOUND=0
LEVELDB_CMAKE_ON=	-DENABLE_LEVELDB=1
LEVELDB_CMAKE_OFF=	-DENABLE_LEVELDB=0
LEVELDB_LIB_DEPENDS=	libleveldb.so:databases/leveldb
FREETYPE_CMAKE_ON=	-DENABLE_FREETYPE=1
FREETYPE_CMAKE_OFF=	-DENABLE_FREETYPE=0
FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT} && ${PORT_OPTIONS:MSOUND}
USES+=		openal
LIB_DEPENDS+=	libvorbis.so:audio/libvorbis
.endif

.if ${PORT_OPTIONS:MSERVER}
USE_RC_SUBR=	${PORTNAME}
USERS=		minetest # reuse, as freeminer is a fork of
GROUPS=		minetest
.endif

# hacky way to not bring irrlicht and X11 depends for server only
.if ! ${PORT_OPTIONS:MCLIENT} && ${PORT_OPTIONS:MSERVER}
BUILD_DEPENDS+=	${NONEXISTENT}:x11-toolkits/irrlicht:patch
IRRLICHT_INCLUDE_DIR=	`${MAKE} -C ${PORTSDIR}/x11-toolkits/irrlicht -V WRKSRC`/include
CMAKE_ARGS+=	-DIRRLICHT_INCLUDE_DIR:STRING="${IRRLICHT_INCLUDE_DIR}"
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-irrlichtdepend
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/cmake/Modules/*.cmake
	@${REINPLACE_CMD} -e 's|-lpthread|-pthread|' \
		${WRKSRC}/src/CMakeLists.txt
.if ! ${PORT_OPTIONS:MLUAJIT}
	@${REINPLACE_CMD} -e '/find_/ s|LUA_|NO&|g' \
		${WRKSRC}/src/CMakeLists.txt
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/games
	@${MV} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.example \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
