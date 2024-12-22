PORTNAME=	hyprgraphics
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	graphics

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	0f9b8ca692b3.patch:-p1 # https://github.com/hyprwm/hyprgraphics/pull/3

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Hyprland graphics / resource utilities
WWW=		https://github.com/hyprwm/hyprgraphics

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhyprutils.so:devel/hyprutils \
		libjxl.so:graphics/libjxl \
		libwebp.so:graphics/webp

USES=		cmake:testing compiler:c++11-lib gnome jpeg pkgconfig xorg
USE_GITHUB=	yes
USE_GNOME=	cairo
USE_LDCONFIG=	yes
USE_XORG=	pixman
GH_ACCOUNT=	hyprwm
PLIST_SUB=	VERSION=${DISTVERSION:C/-.*//}

.include <bsd.port.mk>
