PORTNAME=	toppler
PORTVERSION=	1.3
PORTREVISION=	4
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Climb a tower and avoid monsters
WWW=		https://gitlab.com/roever/toppler/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png
BUILD_DEPENDS=	gimp:graphics/gimp-app \
		povray:graphics/povray-meta

USES=		gmake magick:build sdl pkgconfig
USE_GITLAB=	yes
GL_ACCOUNT=	roever
GL_TAGNAME=	5e3e581bb7b58098f54df9b634c7bd4a23ba66b5
USE_SDL=	sdl2 image2 mixer2

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_LIBS=	-L${LOCALBASE}/lib -lintl
NLS_USES=	gettext
NLS_USES_OFF=	gettext-tools

post-extract:
	@${MV} ${WRKSRC}/src/version ${WRKSRC}

post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's|ENABLE_NLS=1|ENABLE_NLS=0|' ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}/var/games/toppler
	@${TOUCH} ${STAGEDIR}/var/games/toppler/toppler.hsc.sample
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/toppler
	${INSTALL_DATA} ${WRKSRC}/dist/toppler.xpm ${STAGEDIR}${PREFIX}/share/pixmaps
	@${SED} -e 's|@prefix@|${PREFIX}|' \
		< ${WRKSRC}/dist/toppler.desktop.in \
		> ${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}.desktop

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
