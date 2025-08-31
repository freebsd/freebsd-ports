PORTNAME=	sdl3_ttf
DISTVERSIONPREFIX=	release-
DISTVERSION=	3.2.2
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Library to use TrueType fonts to render text in SDL applications
WWW=		https://github.com/libsdl-org/SDL_ttf

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		cmake pkgconfig sdl
USE_GITHUB=	yes
GH_ACCOUNT=	libsdl-org
GH_PROJECT=	SDL_ttf
USE_LDCONFIG=	yes
USE_SDL=	sdl3
CMAKE_OFF=	SDLTTF_SAMPLES

PLIST_SUB=	LIBVERSION=${DISTVERSION:C/[0-9]+/0/1}

PORTDOCS=	*

OPTIONS_DEFINE=	HARFBUZZ PLUTOSVG DOCS
OPTIONS_DEFAULT=HARFBUZZ PLUTOSVG
OPTIONS_SUB=	yes

HARFBUZZ_DESC=		Use harfbuzz to improve text shaping
HARFBUZZ_LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz
HARFBUZZ_CMAKE_BOOL=	SDLTTF_HARFBUZZ

PLUTOSVG_DESC=		Use plutosvg for color emoji support
PLUTOSVG_LIB_DEPENDS=	libplutosvg.so:graphics/plutosvg \
			libplutovg.so:graphics/plutovg
PLUTOSVG_CMAKE_BOOL=	SDLTTF_PLUTOSVG

post-extract:
	@${RM} -r ${WRKSRC}/external

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES.txt ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
