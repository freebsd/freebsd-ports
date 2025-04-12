PORTNAME=	agg
DISTVERSION=	2.6
PORTREVISION=	0
CATEGORIES=	graphics
PKGNAMESUFFIX=	26${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	High Quality Rendering Engine for C++
WWW=		https://github.com/ghaerr/agg-2.6

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/copying

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		cpe localbase gmake libtool pkgconfig \
		autoreconf pathfix xorg sdl
CONFLICTS=      agg-2.*
CPE_VENDOR=	antigrain
USE_GITHUB=	yes
GH_ACCOUNT=	ghaerr
GH_PROJECT=	${PORTNAME}-${PORTVERSION}
GH_TAGNAME=	c4f36b44 # 20230821
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes
USE_SDL=	sdl2
USE_XORG=	x11

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${GH_PROJECT}-${GH_TAGNAME}/agg-src

INSTALL_TARGET=	install-strip

post-patch:
	${REINPLACE_CMD} \
		's|agg_platform_support.cpp|../sdl2/agg_platform_support.cpp|' \
		 ${WRKSRC}/src/platform/sdl/Makefile.am
	${REINPLACE_CMD} 's|_LDFLAGS|_LDADD|' ${WRKSRC}/examples/Makefile.am

.include <bsd.port.mk>
