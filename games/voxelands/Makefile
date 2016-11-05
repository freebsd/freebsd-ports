# $FreeBSD$

PORTNAME=		voxelands
PORTVERSION=		1604.00
PORTREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://voxelands.com/downloads/
DISTNAME=		${PORTNAME}-${PORTVERSION}-src

MAINTAINER=		dcmenche@gmail.com
COMMENT?=		Fun-Focused voxel world game

LICENSE=		GPLv3+

LIB_DEPENDS=		libIrrlicht.so:x11-toolkits/irrlicht \
			libfreetype.so:print/freetype2

USES=			cmake tar:bzip2

WRKSRC=			${WRKDIR}/${PORTNAME}

OPTIONS_SUB=		yes

OPTIONS_DEFINE=		NLS SOUND SQLITE3
OPTIONS_MULTI=		BINARIES
OPTIONS_MULTI_BINARIES=	CLIENT SERVER

OPTIONS_DEFAULT=	SOUND CLIENT SERVER

OPTIONS_SLAVE?=		CLIENT
OPTIONS_EXCLUDE?=	SERVER

SOUND_DESC=		Enable menu background music and in-game sound effects
SQLITE3_DESC=		Use bundled SQLite3 instead of databases/sqlite3

CLIENT_CMAKE_BOOL=	BUILD_CLIENT
CLIENT_LIB_DEPENDS=	libpng.so:graphics/png
CLIENT_USE=		xorg=x11,xxf86vm gl=gl
CLIENT_USES=		jpeg
NLS_USES=		gettext
NLS_CMAKE_BOOL=		GETTEXT_FOUND
SERVER_CMAKE_BOOL=	BUILD_SERVER
SQLITE3_CMAKE_ON=	-DSQLITE3_INCLUDE_DIR=SQLITE3_INCLUDE_DIR-NOTFOUND \
			SQLITE3_LIBRARY=SQLITE3_LIBRARY-NOTFOUND
SQLITE3_LIB_DEPENDS_OFF=libsqlite3.so:databases/sqlite3
SOUND_CMAKE_BOOL=	ENABLE_AUDIO
SOUND_LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
			libogg.so:audio/libogg \
			libopenal.so:audio/openal-soft

.include <bsd.port.mk>
