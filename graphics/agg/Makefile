PORTNAME=	agg
DISTVERSION=	2.7.0
PORTREVISION=	0
CATEGORIES=	graphics

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	High Quality Rendering Engine for C++
WWW=		https://github.com/clausecker/agg

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/copying

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		cpe localbase gmake libtool pkgconfig \
		autoreconf pathfix xorg sdl
CONFLICTS=      agg-2.*
CPE_VENDOR=	antigrain
USE_GITHUB=	yes
GH_ACCOUNT=	clausecker
GH_TAGNAME=	b064760 # 2024-09-28
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes
USE_SDL=	sdl
USE_XORG=	x11

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

post-patch:
	${REINPLACE_CMD} 's|_LDFLAGS|_LDADD|' ${WRKSRC}/examples/Makefile.am

.include <bsd.port.mk>
