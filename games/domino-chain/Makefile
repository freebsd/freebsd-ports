PORTNAME=	domino-chain
PORTVERSION=	1.1
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Rearrange dominoes on different platforms to start a chain reaction

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png \
		libfribidi.so:converters/fribidi \
		libboost_filesystem.so:devel/boost-libs
BUILD_DEPENDS=	povray:graphics/povray-meta \
		convert:graphics/ImageMagick7
RUN_DEPENDS=	${FREESANS_DIR}/FreeSans.ttf:x11-fonts/freefont-ttf

USES=		compiler:c++17-lang gettext gmake lua:52 pkgconfig sdl
USE_GITLAB=	yes
GL_PROJECT=	domino-chain.gitlab.io
GL_COMMIT=	3969eaa66f753e873eca4ef33b263ca1307be2df
USE_SDL=	sdl2 mixer2 ttf2 image2

LIBS+=		${LOCALBASE}/lib/libintl.so

FREESANS_DIR=	${LOCALBASE}/share/fonts/freefont-ttf

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

post-patch:
	@${REINPLACE_CMD} -e '/fontpaths.*=/,/^}/ s|".*fonts.*"|"${FREESANS_DIR}"|' \
		${WRKSRC}/src/domino-chain/screen.cpp

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${WRKSRC}/AUTHORS ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
