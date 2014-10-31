# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	thegrind
PORTVERSION=	0.1.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/radius-engine/ld21/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple game about escaping from work

LICENSE=	GPLv2

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

PORTDOCS=	ChangeLog
OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
