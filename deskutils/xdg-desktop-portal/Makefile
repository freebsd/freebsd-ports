PORTNAME=	xdg-desktop-portal
PORTVERSION=	1.18.2
CATEGORIES=	deskutils wayland

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Portal frontend service for Flatpak
WWW=		https://github.com/flatpak/xdg-desktop-portal

LICENSE=	LGPL21

LIB_DEPENDS=	libfuse3.so:sysutils/fusefs-libs3 \
		libgeoclue-2.so:net/geoclue \
		libjson-glib-1.0.so:devel/json-glib \
		libpipewire-0.3.so:multimedia/pipewire \
		libportal.so:deskutils/libportal

USES=		gettext-tools gmake gnome meson pkgconfig

USE_GNOME=	gdkpixbuf2 glib20

USE_GITHUB=	yes
GH_ACCOUNT=	flatpak

MESON_ARGS=	-Ddocbook-docs=disabled -Dman-pages=disabled -Dpytest=disabled \
		-Dflatpak-interfaces=disabled -Dsandboxed-image-validation=false \
		-Dsystemd=disabled

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/systemd

.include <bsd.port.mk>
