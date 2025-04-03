PORTNAME=	xdg-desktop-portal
PORTVERSION=	1.20.0
PORTREVISION=	2
CATEGORIES=	deskutils

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Portal frontend service for Flatpak
WWW=		https://github.com/flatpak/xdg-desktop-portal/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfuse3.so:filesystems/fusefs-libs3 \
		libgeoclue-2.so:net/geoclue \
		libgudev-1.0.so.0:devel/libgudev \
		libjson-glib-1.0.so:devel/json-glib \
		libpipewire-0.3.so:multimedia/pipewire \
		libportal.so:deskutils/libportal

USES=		gettext-tools gmake gnome gstreamer meson pkgconfig python:build shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	flatpak
USE_GNOME=	gdkpixbuf glib20

MESON_ARGS=	-Ddocumentation=disabled \
		-Dflatpak-interfaces=disabled \
		-Dsandboxed-image-validation=disabled \
		-Dsandboxed-sound-validation=disabled \
		-Dsystemd=disabled \
		-Dtests=disabled

SHEBANG_FILES=	src/generate-method-info.py

OPTIONS_DEFINE=	MANPAGES

MANPAGES_BUILD_DEPENDS=	rst2man:textproc/py-docutils
MANPAGES_MESON_ENABLED=	man-pages

OPTIONS_SUB=	yes

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/systemd

.include <bsd.port.mk>
