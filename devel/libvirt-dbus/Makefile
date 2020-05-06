# $FreeBSD$

PORTNAME=	libvirt-dbus
PORTVERSION=	1.4.0
CATEGORIES=	devel
MASTER_SITES=	ftp://libvirt.org/libvirt/dbus/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Libvirt D-Bus API binding

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvirt.so:devel/libvirt \
	        libvirt-glib-1.0.so:devel/libvirt-glib
RUN_DEPENDS=	dbus-daemon:devel/dbus
BUILD_DEPENDS=	rst2man:textproc/py-docutils

USES=		gettext-runtime gmake gnome libtool perl5 pkgconfig tar:xz meson
USE_GNOME=	glib20
USE_PERL5=	build

USERS=		libvirtdbus
GROUPS=		libvirtdbus

.include <bsd.port.mk>
