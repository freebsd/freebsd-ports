# Created by: Frank W. Josellis <frank@dynamical-systems.org>
# $FreeBSD$

PORTNAME=	sdlCC
PORTVERSION=	0.0.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://jcatki.no-ip.org/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible Chinese checkers game using SDL

LICENSE=	GPLv2

USES=		libtool:keepla # ltdl used, .la may be needed to load plugins
USE_SDL=	image mixer sdl
GNU_CONFIGURE=	yes
MAKE_ENV=	INSTALL_STRIP_FLAG=${STRIP}

PORTDOCS=	*
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Chinese Checkers" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/libltdl/configure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/players/README ${STAGEDIR}${DOCSDIR}/README.players
	${LN} -sf /usr/local/lib/sdlCC/images/CC.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
