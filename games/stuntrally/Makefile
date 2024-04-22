PORTNAME=	stuntrally
PORTVERSION=	2.7
PORTREVISION=	3
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	3D racing game based on VDrift and OGRE with track editor
WWW=		https://stuntrally.tuxfamily.org/ \
		https://github.com/stuntrally/stuntrally/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/License.txt

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libOgreMain.so:graphics/ogre3d \
		libBulletDynamics.so:devel/bullet \
		libMyGUIEngine.so:x11-toolkits/mygui \
		libogg.so:audio/libogg \
		libvorbisfile.so:audio/libvorbis \
		libenet.so:net/enet \
		libtinyxml.so:textproc/tinyxml \
		libtinyxml2.so:textproc/tinyxml2
BUILD_DEPENDS=	${LOCALBASE}/include/MYGUI/MyGUI_OgreTexture.h:x11-toolkits/mygui-ogre

USES=		compiler:c++14-lang cmake pkgconfig sdl
USE_SDL=	sdl2
USE_GITHUB=	yes
GH_TUPLE=	stuntrally:tracks:${PORTVERSION}:tracks/data/tracks
CMAKE_ARGS=	-DSHARE_INSTALL="${DATADIR_REL}" \
		-DBULLET_ROOT="${LOCALBASE}"
CMAKE_ON=	SR_FORCE_SYSTEM_DEPENDENCIES

LDFLAGS_i386=	-Wl,-znotext

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	GAME EDITOR TRANSLATOR MASTER_SERVER DOCS
OPTIONS_DEFAULT=GAME EDITOR TRANSLATOR
OPTIONS_SUB=	yes

GAME_DESC=		Build the game binary
GAME_CMAKE_BOOL=	BUILD_GAME
GAME_USES=		openal

EDITOR_DESC=		Build the track editor
EDITOR_CMAKE_BOOL=	BUILD_EDITOR
EDITOR_USES=		openal

TRANSLATOR_DESC=	Build translation tool
TRANSLATOR_CMAKE_BOOL=	BUILD_TRANSL_TOOL

MASTER_SERVER_CMAKE_BOOL=	BUILD_MASTER_SERVER
MASTER_SERVER_DESC=		Build the master server

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Readme.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
