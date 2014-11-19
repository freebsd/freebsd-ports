# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libvirt-glib
PORTVERSION=	0.1.9
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://libvirt.org/libvirt/glib/

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Glib bindings for Libvirt virtualization API

LIB_DEPENDS=	libvirt.so:${PORTSDIR}/devel/libvirt

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-introspection
USES=		gmake libtool pathfix pkgconfig python:2
USE_LDCONFIG=	yes
USE_GNOME=	intlhack introspection
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-fstack-protector
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

SHLIB_VER=	1.0

.include <bsd.port.mk>
