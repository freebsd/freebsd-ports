PORTNAME=	drm_info
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.0
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Small utility to dump info about DRM devices
WWW=		https://gitlab.freedesktop.org/emersion/drm_info

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjson-c.so:devel/json-c \
		libdrm.so:graphics/libdrm

USES=		compiler:c11 meson pkgconfig
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	emersion
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	MANPAGES PCI
OPTIONS_DEFAULT=MANPAGES PCI

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

PCI_DESC=		Print PCI device names via libpci
PCI_LIB_DEPENDS=	libpci.so:devel/libpci
PCI_MESON_ENABLED=	libpci

.include <bsd.port.mk>
