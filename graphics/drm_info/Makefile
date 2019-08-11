# $FreeBSD$

PORTNAME=	drm_info
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.0
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Small utility to dump info about DRM devices

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjson-c.so:devel/json-c \
		libdrm.so:graphics/libdrm

USES=		compiler:c11 meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	ascent12
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
