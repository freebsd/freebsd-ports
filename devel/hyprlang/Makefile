PORTNAME=	hyprlang
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.3
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Library to parse hypr config files
WWW=		https://hyprland.org/hyprlang

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhyprutils.so:devel/hyprutils

USES=		cmake:testing compiler:c++11-lib pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	hyprwm
PLIST_FILES=	include/${PORTNAME}.hpp \
		lib/lib${PORTNAME}.so \
		lib/lib${PORTNAME}.so.2 \
		lib/lib${PORTNAME}.so.${PORTVERSION} \
		libdata/pkgconfig/${PORTNAME}.pc

.include <bsd.port.mk>
