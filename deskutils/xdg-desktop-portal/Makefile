PORTNAME=	xdg-desktop-portal
DISTVERSION=	1.22.1
CATEGORIES=	deskutils

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Portal frontend service for Flatpak
WWW=		https://github.com/flatpak/xdg-desktop-portal/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfuse3.so:filesystems/fusefs-libs3 \
		libgeoclue-2.so:net/geoclue \
		libgudev-1.0.so:devel/libgudev \
		libjson-glib-1.0.so:devel/json-glib \
		libpipewire-0.3.so:multimedia/pipewire \
		libportal.so:deskutils/libportal

USES=		cpe gettext-tools gmake gnome gstreamer meson pkgconfig \
		python:build shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	flatpak
USE_GNOME=	gdkpixbuf glib20
USE_GITLAB=	nodefault
GL_TUPLE=	https://gitlab.gnome.org:arrowd:libglnx:c210033e145361b5f5125d79dff4f901c01aa3f7:libglnx/subprojects/libglnx \
		https://gitlab.gnome.org:GNOME:gvdb:c6f2359cc1d00f16e0a0e2527fa0bc1882b8b5ab:gvdb/subprojects/gvdb

SHEBANG_FILES=	src/generate-method-info.py

MESON_ARGS=	-Ddocumentation=disabled \
		-Dflatpak-interfaces=disabled \
		-Dsandboxed-image-validation=disabled \
		-Dsandboxed-sound-validation=disabled \
		-Dsystemd=disabled \
		-Dtests=disabled

OPTIONS_DEFINE=	MANPAGES
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	rst2man:textproc/py-docutils
MANPAGES_MESON_ENABLED=	man-pages

CPE_VENDOR=	flatpak

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/systemd

.include <bsd.port.mk>
