# Created by: Rusmir Dusko <nemysis@FreeBSD.org>

PORTNAME=	fbg2
PORTVERSION=	0.4
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF/fbg/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Classic block-stacking arcade game

LICENSE=	GPLv2+ CC-BY-SA-3.0
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/License.txt

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
PLIST_DIRS=	%%DATADIR%%

PORTDOCS=	ChangeLog
OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
