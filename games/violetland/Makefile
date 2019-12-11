# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	violetland
PORTVERSION=	0.5
PORTREVISION=	16
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Top-down survival shoot 'em up

LICENSE=	GPLv3 CC-BY-SA-3.0
LICENSE_COMB=	multi
#LICENSE_FILE_GPLv3=		"${WRKSRC}/LICENSE (code)" # framework doesn't handle these properly
#LICENSE_FILE_CC-BY-SA-3.0=	"${WRKSRC}/LICENSE (content)"

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	ooxi
GH_TUPLE=	jarro2783:CMake-Gettext:6ee6405:cmakegettext/lib/CMake-Gettext

USES=		cmake compiler:c++11-lang gettext gl sdl
USE_SDL=	sdl mixer image ttf
USE_GL=		gl glu
USE_CXXSTD=	c++98
CMAKE_ARGS=	-DDATA_INSTALL_DIR="${DATADIR}" \
		-DLOCALE_INSTALL_DIR="${PREFIX}/share/locale"

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/icon-light.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} CHANGELOG.md README.md README_RU.TXT \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
