# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	thegrind
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/radius-engine/ld21/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Simple game about escaping from work

LICENSE=	GPLv2

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

PORTDOCS=	ChangeLog

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
