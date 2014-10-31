# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cretan-hubris
PORTVERSION=	0.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/radius-engine/egp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Maze on the Isle of Crete

LICENSE=	GPLv2 CCbyNCSA3
LICENSE_COMB=	dual
LICENSE_NAME_CCbyNCSA3=Attribution-NonCommercial-ShareAlike 3.0 Unported
LICENSE_FILE=	${WRKSRC}/License.txt
LICENSE_FILE_CCbyNCSA3=${WRKSRC}/License.txt
LICENSE_PERMS_CCbyNCSA3=dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	${LOCALBASE}/lib/libradius-engine.a:${PORTSDIR}/graphics/radius-engine
LIB_DEPENDS=	liblua-5.1.so:${PORTSDIR}/lang/lua51 \
		libpng15.so:${PORTSDIR}/graphics/png \
		libphysfs.so.1:${PORTSDIR}/devel/physfs
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

.include <bsd.port.mk>
