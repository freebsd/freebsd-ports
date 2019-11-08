# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libvirt-glib
PORTVERSION=	2.0.0
CATEGORIES=	devel
MASTER_SITES=	ftp://libvirt.org/libvirt/glib/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Glib bindings for Libvirt virtualization API

LICENSE=	GPLv2

LIB_DEPENDS=	libvirt.so:devel/libvirt

OPTIONS_DEFINE=	VALA
OPTIONS_SUB=	yes
VALA_DESC=	Vala binding
VALA_CONFIGURE_ENABLE=	vala
VALA_BUILD_DEPENDS=	valac:lang/vala

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-introspection
USES=		gettext gmake gnome libtool pathfix pkgconfig python:2.7
USE_LDCONFIG=	yes
USE_GNOME=	intlhack introspection libxml2
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-fstack-protector
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

SHLIB_VER=	${PORTVERSION:C/(^[0-9])\./0.\100/}
PLIST_SUB=	VERSION=1.0 \
		SHLIB_VER=${SHLIB_VER}

.include <bsd.port.mk>
