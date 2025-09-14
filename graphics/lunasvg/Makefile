PORTNAME=	lunasvg
DISTVERSIONPREFIX=	v
DISTVERSION=	3.5.0
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

EXTRACT_AFTER_ARGS=	--exclude plutovg --no-same-owner --no-same-permissions

PLIST_SUB=	SOVERSION=${DISTVERSION}

OPTIONS_DEFINE=	STATIC
OPTIONS_SUB=	yes

STATIC_MESON_ON=	-Ddefault_library=both

.include <bsd.port.mk>
