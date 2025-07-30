PORTNAME=	hyprlang
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.4
CATEGORIES=	devel

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Official implementation library for the hypr config language
WWW=		https://wiki.hypr.land/Hypr-Ecosystem/hyprlang/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhyprutils.so:devel/hyprutils

USES=		cmake:testing compiler:c++11-lib pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm

USE_LDCONFIG=	yes

PLIST_FILES=	include/${PORTNAME}.hpp \
		lib/lib${PORTNAME}.so \
		lib/lib${PORTNAME}.so.2 \
		lib/lib${PORTNAME}.so.0.6.3 \
		libdata/pkgconfig/${PORTNAME}.pc

.include <bsd.port.mk>
