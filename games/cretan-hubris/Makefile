# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cretan-hubris
PORTVERSION=	0.2
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/radius-engine/egp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Maze on the Isle of Crete

LICENSE=	GPLv2+ CC-BY-SA-3.0
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/License.txt

BUILD_DEPENDS=	${LOCALBASE}/lib/libradius-engine.a:graphics/radius-engine
LIB_DEPENDS=	liblua-5.1.so:lang/lua51 \
		libpng.so:graphics/png \
		libphysfs.so:devel/physfs
RUN_DEPENDS=	zip:archivers/zip

USES=		gl pkgconfig sdl
USE_SDL=	sdl sound
USE_GL=		glu
GNU_CONFIGURE=	yes
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png \
		%%DATADIR%%/${PORTNAME}.zip

.include <bsd.port.mk>
