PORTNAME=	wayland-utils
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	1.0.0
CATEGORIES=	graphics

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	d367b894f9c8.patch:-p1 # https://gitlab.freedesktop.org/wayland/wayland-utils/-/merge_requests/1

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Display information about protocols supported by Wayland compositor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	wayland-protocols>=1.18:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		meson pkgconfig
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	wayland
GL_COMMIT=	1664a20eb1dfd830113a38d02ad0937de73e4f90
PLIST_FILES=	bin/wayland-info \
		man/man1/wayland-info.1.gz

.include <bsd.port.mk>
