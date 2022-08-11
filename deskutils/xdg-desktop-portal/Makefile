PORTNAME=	xdg-desktop-portal
PORTVERSION=	1.10.1
CATEGORIES=	deskutils wayland

PATCH_SITES=	https://arrowd.name/:freebsd_compat
PATCHFILES=	552.patch:-p1:freebsd_compat

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Portal frontend service for Flatpak

LICENSE=	LGPL21

LIB_DEPENDS=	libfuse.so:sysutils/fusefs-libs \
		libgeoclue-2.so:net/geoclue \
		libjson-glib-1.0.so:devel/json-glib \
		libpipewire-0.3.so:multimedia/pipewire \
		libportal.so:deskutils/libportal

USES=		autoreconf gettext-tools gmake gnome libtool pkgconfig

USE_GNOME=	glib20

GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	flatpak

.include <bsd.port.pre.mk>

.if (${OSVERSION} >= 1400000 && ${OSVERSION} < 1400008) \
 || (${OSVERSION} >= 1300000 && ${OSVERSION} < 1300501) \
 || ${OSVERSION} < 1300000
IGNORE=		requires O_PATH support in open(2)
.endif

.include <bsd.port.post.mk>
