PORTNAME=	stuntrally
PORTVERSION=	2.6.1
PORTREVISION=	4
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	3D racing game based on VDrift and OGRE with track editor

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/License.txt

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USE_GITHUB=	yes
GH_TUPLE=	stuntrally:tracks:${PORTVERSION}:tracks/data/tracks

USES=		compiler:c++11-lib cmake dos2unix pkgconfig sdl
USE_CXXSTD=	gnu++11
DOS2UNIX_FILES=	source/ogre/BaseApp_Create.cpp
CMAKE_ARGS=	-DSHARE_INSTALL="${DATADIR_REL}" \
		-DBULLET_ROOT="${LOCALBASE}"

LDFLAGS_i386=	-Wl,-znotext

PORTDOCS=	Readme.txt
PORTDATA=	*

OPTIONS_DEFINE=	GAME EDITOR MASTER_SERVER DOCS
OPTIONS_DEFAULT=GAME EDITOR
OPTIONS_SUB=	yes

GAME_DESC=		Build the game binary
GAME_CMAKE_BOOL=	BUILD_GAME
GAME_LIB_DEPENDS=	libOgreMain.so:graphics/ogre3d19 \
			libBulletDynamics.so:devel/bullet \
			libMyGUIEngine.so:x11-toolkits/mygui \
			libogg.so:audio/libogg \
			libvorbisfile.so:audio/libvorbis \
			libenet.so:net/enet
GAME_BUILD_DEPENDS=	${LOCALBASE}/include/MYGUI/MyGUI_OgreTexture.h:x11-toolkits/mygui-ogre
GAME_USE=		SDL=sdl2
GAME_USES=		openal

EDITOR_DESC=		Build the track editor
EDITOR_CMAKE_BOOL=	BUILD_EDITOR
EDITOR_LIB_DEPENDS=	libOgreMain.so:graphics/ogre3d19 \
			libBulletDynamics.so:devel/bullet \
			libMyGUIEngine.so:x11-toolkits/mygui \
			libogg.so:audio/libogg \
			libvorbisfile.so:audio/libvorbis
EDITOR_USE=		SDL=sdl2
EDITOR_BUILD_DEPENDS=	${LOCALBASE}/include/MYGUI/MyGUI_OgreTexture.h:x11-toolkits/mygui-ogre

MASTER_SERVER_CMAKE_BOOL=	BUILD_MASTER_SERVER
MASTER_SERVER_DESC=		Build the master server
MASTER_SERVER_LIB_DEPENDS=	libenet.so:net/enet

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Readme.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
