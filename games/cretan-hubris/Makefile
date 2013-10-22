# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	cretan-hubris
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/radius-engine/egp/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Maze on the Isle of Crete

LICENSE=	GPLv2 CCbyNCSA3
LICENSE_COMB=	dual
LICENSE_NAME_CCbyNCSA3=Attribution-NonCommercial-ShareAlike 3.0 Unported
LICENSE_FILE=	${WRKSRC}/License.txt
LICENSE_FILE_CCbyNCSA3=${WRKSRC}/License.txt
LICENSE_PERMS_CCbyNCSA3=dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	${LOCALBASE}/lib/libradius-engine.a:${PORTSDIR}/graphics/radius-engine
LIB_DEPENDS=	lua-5.1:${PORTSDIR}/lang/lua \
		png15:${PORTSDIR}/graphics/png \
		physfs.1:${PORTSDIR}/devel/physfs
RUN_DEPENDS=	zip:${PORTSDIR}/archivers/zip

USES=		pkgconfig
USE_SDL=	sdl sound
USE_GL=		glu
GNU_CONFIGURE=	yes
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png \
		%%DATADIR%%/${PORTNAME}.zip
PLIST_DIRS=	%%DATADIR%%

NO_STAGE=	yes
.include <bsd.port.mk>
