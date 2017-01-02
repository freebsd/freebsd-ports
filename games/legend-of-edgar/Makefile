# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	edgar
DISTVERSION=	1.26
CATEGORIES=	games
PKGNAMEPREFIX=	legend-of-

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	2D platform game with a persistent world

LICENSE=	GPLv2

USES=		gmake
USE_SDL=	image mixer sdl ttf
WITH_ZLIB=	yes
MAKEFILE=	makefile

USE_GITHUB=	yes
GH_ACCOUNT=	riksweeney

PORTDOCS=	*

INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DOCS NLS

OPTIONS_SUB=	yes

NLS_USES=		gettext

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|CC       = gcc|CC       = ${CC}|; \
		s|$$(DESTDIR)/usr|$$(DESTDIR)/usr/local|; \
		s|$$(PREFIX)/games/|$$(PREFIX)/bin/|; \
		s|/share/games/edgar/|/share/edgar/|; \
		s|/share/man/|/man/|; \
		s|-Wall ||; \
		s|sdl-config|${SDL_CONFIG}|; \
		s|-s ||' \
		${WRKSRC}/makefile
	@${REINPLACE_CMD} -e 's|SDL/SDL|${LOCALBASE}/include/SDL/SDL|g' \
		${WRKSRC}/src/headers.h
	@${REINPLACE_CMD} -e 's|png.h|${LOCALBASE}/include/png.h|g' \
		${WRKSRC}/src/graphics/save_png.c
	@${REINPLACE_CMD} -e 's|self->dirY =- 13|self->dirY -= 13|g' \
		${WRKSRC}/src/boss/golem_boss.c
	@${REINPLACE_CMD} -e 's|Categories=Game|Categories=Game;ArcadeGame;|' \
		${WRKSRC}/icons/${PORTNAME}.desktop

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
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
