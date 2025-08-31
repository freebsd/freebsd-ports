PORTNAME=	plutosvg
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.7
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Tiny SVG rendering library in C
WWW=		https://github.com/sammycage/plutosvg/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libplutovg.so:graphics/plutovg

USES=		cpe meson pkgconfig
CPE_VENDOR=	sammycage
USE_GITHUB=	yes
GH_ACCOUNT=	sammycage
USE_LDCONFIG=	yes

PLIST_SUB=	SOVERSION=${DISTVERSION}

OPTIONS_DEFINE=		FREETYPE STATIC
OPTIONS_DEFAULT=	FREETYPE
OPTIONS_SUB=		yes

FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
FREETYPE_MESON_ENABLED=	freetype
STATIC_MESON_ON=	-Ddefault_library=both

.include <bsd.port.mk>
