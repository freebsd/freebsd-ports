# Created by: Rusmir Dusko <nemysis@FreeBSD.org>

PORTNAME=	thegrind
PORTVERSION=	0.1.2
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/radius-engine/ld21/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple game about escaping from work

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/License.txt

BUILD_DEPENDS=	${LOCALBASE}/lib/libradius-engine.a:graphics/radius-engine
LIB_DEPENDS=	liblua-5.1.so:lang/lua51 \
		libpng.so:graphics/png \
		libphysfs.so.1:devel/physfs
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
