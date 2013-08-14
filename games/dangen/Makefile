# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	dangen
PORTVERSION=	0.5
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.interq.or.jp/libra/oohara/dangen/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Shoot'em up game where accurate shooting matters

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl image
DESKTOP_ENTRIES="dangen" \
		"Shoot'em up game where accurate shooting matters" \
		"" \
		"dangen" \
		"Game;ArcadeGame;" \
		false

PORTDOCS=	*

PLIST_FILES=	bin/${PORTNAME} %%DATADIR%%/image/font.png
PLIST_DIRS=	%%DATADIR%%/image %%DATADIR%%

MAN6=		dangen.6

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|' ${WRKSRC}/Makefile.in \
		${WRKSRC}/libtenm/Makefile.in ${WRKSRC}/spqr/Makefile.in
	@${REINPLACE_CMD} -e 's|$$(datadir)/games/|$$(datadir)/|' ${WRKSRC}/spqr/image/Makefile.in
	@${REINPLACE_CMD} -e 's|/games||' ${WRKSRC}/util.c

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
