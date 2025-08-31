PORTNAME=	lbreakouthd
PORTVERSION=	1.1.11
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/lgames/${PORTNAME}/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Breakout-style arcade game
WWW=		https://lgames.sourceforge.io/LBreakout2/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf localbase sdl
USE_SDL=	sdl2 mixer2 image2 ttf2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var/games/${PORTNAME}

PORTDOCS=	ChangeLog README
PORTDATA=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

post-install:
	@${MV} ${STAGEDIR}/var/games/${PORTNAME}/${PORTNAME}.hscr ${STAGEDIR}/var/games/${PORTNAME}/${PORTNAME}.hscr.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
