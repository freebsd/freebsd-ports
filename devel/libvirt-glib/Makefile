# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libvirt-glib
PORTVERSION=	0.2.3
CATEGORIES=	devel
MASTER_SITES=	ftp://libvirt.org/libvirt/glib/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Glib bindings for Libvirt virtualization API

LICENSE=	GPLv2

LIB_DEPENDS=	libvirt.so:devel/libvirt

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-introspection
USES=		gettext gmake libtool pathfix pkgconfig python:2
USE_LDCONFIG=	yes
USE_GNOME=	intlhack introspection
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-fstack-protector
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION=1.0 \
		SHLIB_VER=${PORTVERSION}

.include <bsd.port.mk>
