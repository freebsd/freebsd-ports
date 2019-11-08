# Created by: Edwin Groothuis
# $FreeBSD$

PORTNAME=	bomberclone
PORTVERSION=	0.11.9
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Reimplementation of Atomic Bomber Man

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake localbase sdl
USE_SDL=	image mixer sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-werror

LIBS+=		-lm

PORTDOCS=	AUTHORS ChangeLog README TODO

OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="BomberMan clone" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-extract:
	@${FIND} ${WRKSRC} -type d -name CVS | ${XARGS} ${RM} -r ;

post-patch:
	@${REINPLACE_CMD} -e 's|share/games/${PACKAGE}|share/${PACKAGE}|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} \
		-e 's|install-data-am: install-bomberclonedocDATA|install-data-am: |' \
		${WRKSRC}/Makefile.in

post-install:
	${LN} -sf ${DATADIR}/pixmaps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
