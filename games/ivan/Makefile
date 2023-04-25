PORTNAME=	ivan
PORTVERSION=	0.59
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Graphical roguelike game
WWW=		https://attnam.com/ \
		http://ivan.sourceforge.net/ \
		https://github.com/Attnam/ivan

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libpcre.so:devel/pcre

USES=		cmake pkgconfig sdl
USE_SDL=	sdl2 mixer2
USE_GITHUB=	yes
GH_ACCOUNT=	Attnam
GH_TAGNAME=	v${PORTVERSION:C/\.//}

PLIST_FILES=	bin/ivan

PORTSCOUT=	limit:^0\.[5-9]

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	WIZARD DOCS

WIZARD_DESC=	Enable Wizard mode
WIZARD_CMAKE_BOOL=	WIZARD

post-install-DOCS-on:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "README.md Doc MANUAL" \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
