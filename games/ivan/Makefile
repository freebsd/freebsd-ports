PORTNAME=	ivan
PORTVERSION=	0.58
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Graphical roguelike game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libpcre.so:devel/pcre

USES=		cmake pkgconfig sdl
USE_SDL=	sdl2 mixer2
USE_GITHUB=	yes
GH_ACCOUNT=	Attnam
GH_TAGNAME=	v${PORTVERSION:C/\.//}

CFLAGS+=	-DNOSOUND=1
CXXFLAGS+=	-DNOSOUND=1

PLIST_FILES=	bin/ivan

PORTSCOUT=	skipv:0.301,0.310,0.311,0.401,0.410,0.420,0.430

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	WIZARD DOCS

WIZARD_DESC=	Enable Wizard mode
WIZARD_CMAKE_BOOL=	WIZARD

post-install-DOCS-on:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "README.md Doc MANUAL" \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
