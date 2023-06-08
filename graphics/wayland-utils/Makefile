PORTNAME=	wayland-utils
DISTVERSION=	1.2.0
CATEGORIES=	graphics wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Display information about protocols supported by Wayland compositor
WWW=		https://gitlab.freedesktop.org/wayland/wayland-utils

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	wayland-protocols>=1.20:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		meson pkgconfig
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	wayland
GL_COMMIT=	43cc17bc5333c41b4d6b7b1708191426126cb21a
PLIST_FILES=	bin/wayland-info \
		man/man1/wayland-info.1.gz

OPTIONS_DEFINE=	DRM
OPTIONS_DEFAULT=DRM

DRM_DESC=		Print extra DRM information
DRM_LIB_DEPENDS=	libdrm.so:graphics/libdrm
DRM_MESON_ENABLED=	drm

.include <bsd.port.mk>
