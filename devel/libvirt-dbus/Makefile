PORTNAME=	libvirt-dbus
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://download.libvirt.org/dbus/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Libvirt D-Bus API binding
WWW=		https://libvirt.org/dbus.html

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvirt.so:devel/libvirt \
	        libvirt-glib-1.0.so:devel/libvirt-glib
RUN_DEPENDS=	dbus-daemon:devel/dbus
BUILD_DEPENDS=	rst2man:textproc/py-docutils

USES=		gettext-runtime gmake gnome perl5 pkgconfig tar:xz meson
USE_GNOME=	glib20
USE_PERL5=	build

USERS=		libvirtdbus
GROUPS=		libvirtdbus

.include <bsd.port.mk>
