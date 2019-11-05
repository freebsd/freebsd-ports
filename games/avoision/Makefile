# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	avoision
PORTVERSION=	1.1
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF/avsn/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple collect-dots-avoid-blocks game

LICENSE=	GPLv2+ CC-BY-SA-3.0
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/License.txt

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

PORTDOCS=	ChangeLog

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
