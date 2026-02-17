PORTNAME=	iio-sensor-proxy
DISTVERSION=	3.6
CATEGORIES=	comms

MAINTAINER=	dhs@frame.work
COMMENT=	Proxies sensor devices to applications through D-BUS
WWW=		https://gitlab.freedesktop.org/hadess/iio-sensor-proxy

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
LIB_DEPENDS+=	libudev.so:devel/libudev-devd \
		libgudev-1.0.so:devel/libgudev \
		libpolkit-gobject-1.so:sysutils/polkit

USES=		pkgconfig meson

USE_GNOME=	glib20
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	hadess

MESON_ARGS=	-Dudevrulesdir=disabled \
		-Dsystemdsystemunitdir=disabled

.include <bsd.port.mk>
