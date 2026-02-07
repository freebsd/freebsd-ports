PORTNAME=	dangen
PORTVERSION=	0.5
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://www.interq.or.jp/libra/oohara/dangen/ \
		https://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Shoot'em up game where accurate shooting matters
WWW=		http://www.interq.or.jp/libra/oohara/dangen/index.html

LICENSE=	GPLv2 ART20
LICENSE_COMB=	dual

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		gmake sdl
USE_SDL=	sdl image
DESKTOP_ENTRIES="dangen" \
		"Shoot'em up game where accurate shooting matters" \
		"" \
		"dangen" \
		"Game;ArcadeGame;" \
		false

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man6/${PORTNAME}.6.gz
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|' ${WRKSRC}/Makefile.in \
		${WRKSRC}/libtenm/Makefile.in ${WRKSRC}/spqr/Makefile.in
	@${REINPLACE_CMD} -e 's|$$(datadir)/games/|$$(datadir)/|' ${WRKSRC}/spqr/image/Makefile.in
	@${REINPLACE_CMD} -e 's|/games||' ${WRKSRC}/util.c

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
