# $FreeBSD$

PORTNAME=	libvirt-dbus
PORTVERSION=	1.3.0
CATEGORIES=	devel
MASTER_SITES=	ftp://libvirt.org/libvirt/dbus/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Libvirt D-Bus API binding

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvirt.so:devel/libvirt \
	        libvirt-glib-1.0.so:devel/libvirt-glib
RUN_DEPENDS=	dbus-daemon:devel/dbus

USES=		gettext-runtime gmake gnome libtool perl5 pkgconfig tar:xz
USE_GNOME=	glib20
USE_PERL5=	build

GNU_CONFIGURE=	yes

USERS=		libvirtdbus
GROUPS=		libvirtdbus

.include <bsd.port.mk>
