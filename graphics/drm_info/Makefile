# $FreeBSD$

PORTNAME=	drm_info
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.0
PORTREVISION=	1
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

OPTIONS_DEFINE=	PCI
OPTIONS_DEFAULT=PCI

PCI_DESC=		Print PCI device names via libpci
PCI_LIB_DEPENDS=	libpci.so:devel/libpci
PCI_MESON_ENABLED=	libpci

.include <bsd.port.mk>
