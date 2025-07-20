PORTNAME=	hyprgraphics
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.5
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Hyprland graphics / resource utilities
WWW=		https://github.com/hyprwm/hyprgraphics

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhyprutils.so:devel/hyprutils \
		libjxl.so:graphics/libjxl \
		libpng.so:graphics/png \
		libwebp.so:graphics/webp

USES=		cmake:testing compiler:c++11-lib gnome jpeg pkgconfig xorg
USE_GITHUB=	yes
USE_GNOME=	cairo
USE_LDCONFIG=	yes
USE_XORG=	pixman
GH_ACCOUNT=	hyprwm
PLIST_SUB=	VERSION=${DISTVERSION:C/-.*//}

.include <bsd.port.mk>
