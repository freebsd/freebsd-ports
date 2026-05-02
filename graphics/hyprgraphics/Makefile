PORTNAME=	hyprgraphics
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Hyprland graphics / resource utilities
WWW=		https://github.com/hyprwm/hyprgraphics

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhyprutils.so:devel/hyprutils \
		libdrm.so:graphics/libdrm \
		libheif.so:graphics/libheif \
		libjxl.so:graphics/libjxl \
		libpng.so:graphics/png \
		libwebp.so:graphics/webp

USES=		cmake:testing compiler:c++11-lib gl gnome jpeg pkgconfig xorg

USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm

USE_LDCONFIG=	yes

USE_GL=		opengl
USE_GNOME=	cairo librsvg2 pango
USE_XORG=	pixman

LDFLAGS+=	-pthread

PLIST_SUB=	SOVERSION_MAJOR=4 \
		SOVERSION_FULL=${DISTVERSION:C/-.*//}

.include <bsd.port.mk>
