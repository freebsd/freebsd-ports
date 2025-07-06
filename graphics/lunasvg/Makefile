PORTNAME=	lunasvg
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	alven@FreeBSD.org
COMMENT=	SVG rendering and manipulation library in C++
WWW=		https://github.com/sammycage/lunasvg/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libplutovg.so:graphics/plutovg

USES=		cpe meson pkgconfig
CPE_VENDOR=	sammycage
USE_GITHUB=	yes
GH_ACCOUNT=	sammycage
USE_LDCONFIG=	yes

PLIST_SUB=	SOVERSION=${DISTVERSION}

OPTIONS_DEFINE=		STATIC
OPTIONS_SUB=	yes

STATIC_MESON_ON=	-Ddefault_library=both

.include <bsd.port.mk>
