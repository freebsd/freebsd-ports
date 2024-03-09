PORTNAME=	gnujump
PORTVERSION=	1.0.8
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	GNU

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Platform game where you have to jump up to survive
WWW=		https://jump.gnu.sinusoid.es/index.php?title=Main_Page \
		https://github.com/arximboldi/gnujump

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gl gmake localbase sdl xorg
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_SDL=	sdl mixer image
USE_GL=		gl
USE_XORG=	x11

LDFLAGS+=	-lm

PORTDOCS=	AUTHORS README
PORTDATA=	*

DESKTOP_ENTRIES="GNUJump" \
		"" \
		"${DATADIR}/skins/default/hero1.0.png" \
		"${PORTNAME}" \
		"Game;ArcadeGame;" \
		""

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext
NLS_LDFLAGS=	-lintl

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/src/gnujump.h

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
