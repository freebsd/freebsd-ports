PORTNAME=	plutovg
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	graphics

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Tiny 2D vector graphics library in C
WWW=		https://github.com/sammycage/plutovg/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe meson
CPE_VENDOR=	sammycage
USE_GITHUB=	yes
GH_ACCOUNT=	sammycage
USE_LDCONFIG=	yes

PLIST_SUB=	SOVERSION=${DISTVERSION}

OPTIONS_DEFINE=	STATIC
OPTIONS_SUB=	yes

STATIC_MESON_ON=	-Ddefault_library=both

.include <bsd.port.mk>
