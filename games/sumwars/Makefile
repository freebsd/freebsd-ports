# New ports collection makefile for: games/sumwars
# Date created:		13 Nov 2011
# Whom:			Stas Timokhin <devel@stasyan.com>
#
# $FreeBSD$
#

PORTNAME=	sumwars
PORTVERSION=	0.5.5
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF/sumwars/${PORTVERSION}
DISTNAME=	sumwars-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	devel@stasyan.com
COMMENT=	Role-playing game, featuring both a single and a multiplayer mode

BUILD_DEPENDS=	${LOCALBASE}/lib/libOgreMain.so.1.7.4:${PORTSDIR}/graphics/ogre3d \
		${LOCALBASE}/lib/libOIS-1.2.0.so:${PORTSDIR}/devel/ois \
		${LOCALBASE}/lib/libenet.a:${PORTSDIR}/net/enet
RUN_DEPENDS=	${LOCALBASE}/lib/libOgreMain.so.1.7.4:${PORTSDIR}/graphics/ogre3d \
		${LOCALBASE}/lib/libOIS-1.2.0.so:${PORTSDIR}/devel/ois
LIB_DEPENDS=	CEGUIBase-0.7.7.0:${PORTSDIR}/graphics/cegui \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		PocoNet.12:${PORTSDIR}/devel/poco \
		physfs.1:${PORTSDIR}/devel/physfs

USE_GMAKE=	yes
USE_CMAKE=	yes
USE_GL=		gl glu
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
USE_LUA=	5.1
USE_OPENAL=	al alut
MAKE_JOBS_SAFE=	yes

FETCH_ARGS?=	-pRr

CMAKE_VERBOSE=	yes
CMAKE_ARGS+=	-DGETTEXT_SEARCH_PATH=${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} 's|/usr/lib/OGRE|${LOCALBASE}/lib/OGRE|g' ${WRKSRC}/plugins.cfg \
		${WRKSRC}/src/gui/application.cpp
	@${REINPLACE_CMD} -e 's|/usr/games|${LOCALBASE}/games|g' \
		-e 's|/usr/share|${LOCALBASE}/share|g' ${WRKSRC}/packaging/sumwars.desktop

.include <bsd.port.mk>
