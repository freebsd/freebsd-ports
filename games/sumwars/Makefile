# Created by: Stas Timokhin <devel@stasyan.com>
# $FreeBSD$

PORTNAME=	sumwars
PORTVERSION=	0.5.6
CATEGORIES=	games
MASTER_SITES=	SF/sumwars/${PORTVERSION}
DISTNAME=	sumwars-${PORTVERSION}-src
WRKSRC=		${WRKDIR}/sumwars-${PORTVERSION}
#EXTRACT_SUFX=	.tgz

MAINTAINER=	devel@stasyan.com
COMMENT=	Role-playing game, featuring both a single and a multiplayer mode

BROKEN=		Fails to build

BUILD_DEPENDS=	${LOCALBASE}/lib/libOgreMain.so:${PORTSDIR}/graphics/ogre3d \
		${LOCALBASE}/lib/libOIS-1.2.0.so:${PORTSDIR}/devel/ois \
		${LOCALBASE}/lib/libenet.a:${PORTSDIR}/net/enet
RUN_DEPENDS=	${LOCALBASE}/lib/libOgreMain.so:${PORTSDIR}/graphics/ogre3d \
		${LOCALBASE}/lib/libOIS-1.2.0.so:${PORTSDIR}/devel/ois
LIB_DEPENDS=	CEGUIBase-0.so:${PORTSDIR}/graphics/cegui \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		PocoNet.12:${PORTSDIR}/devel/poco \
		physfs.1:${PORTSDIR}/devel/physfs

USES=		cmake gettext gmake openal:al,alut pkgconfig
USE_GL=		gl glu
USE_BZIP2=	yes
INSTALLS_ICONS=	yes
USE_LUA=	5.1

CMAKE_ARGS+=	-DGETTEXT_SEARCH_PATH=${LOCALBASE}/lib

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} 's|/usr/local/lib/|${LOCALBASE}/lib/|g' ${WRKSRC}/CMakeModules/FindEnet.cmake \
		${WRKSRC}/CMakeModules/FindPhysFS.cmake \
		${WRKSRC}/CMakeModules/FindOGRE.cmake
	@${REINPLACE_CMD} -e 's|/usr/games|${LOCALBASE}/games|g' \
		-e 's|/usr/share|${LOCALBASE}/share|g' ${WRKSRC}/packaging/sumwars.desktop

.include <bsd.port.mk>
