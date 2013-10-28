# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	edgar
DISTVERSION=	1.13-1
CATEGORIES=	games
MASTER_SITES=	SF/legendof${PORTNAME}/${PORTVERSION:R}/
PKGNAMEPREFIX=	legend-of-

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	2D platform game with a persistent world

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:S/-1//}

USES=		gmake
USE_SDL=	image mixer sdl ttf
WITH_ZLIB=	yes
MAKEFILE=	makefile

PORTDOCS=	*

INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DOCS NLS

OPTIONS_SUB=	yes

NLS_USES=		gettext

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|CC       = gcc|CC       = ${CC}|' \
		-e 's|$$(DESTDIR)/usr|${STAGEDIR}${LOCALBASE}|' \
		-e 's|$$(PREFIX)/games/|$$(PREFIX)/bin/|' \
		-e 's|/share/games/edgar/|/share/edgar/|' \
		-e 's|-Wall ||' \
		-e 's|sdl-config|$(SDL_CONFIG)|' \
		-e 's|-s ||' \
		${WRKSRC}/makefile
	@${REINPLACE_CMD} -e 's|SDL/SDL|${LOCALBASE}/include/SDL/SDL|g' \
		${WRKSRC}/src/headers.h
	@${REINPLACE_CMD} -e 's|png.h|${LOCALBASE}/include/png.h|g' \
		${WRKSRC}/src/graphics/save_png.c
	@${REINPLACE_CMD} -e 's|self->dirY =- 13|self->dirY -= 13|g' \
		${WRKSRC}/src/boss/golem_boss.c

.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -i '' -e '/mkdir -p $$(DOC_DIR)/d' \
		-i '' -e '/cp $$(DOCS) $$(DOC_DIR)/d' \
		${WRKSRC}/makefile
.endif

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|^LOCALE_MO =.*|LOCALE_MO =|' \
		${WRKSRC}/makefile
.endif

post-install:
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
