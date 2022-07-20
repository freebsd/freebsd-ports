PORTNAME=	libvirt-glib
PORTVERSION=	4.0.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://libvirt.org/libvirt/glib/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Glib bindings for Libvirt virtualization API

LICENSE=	GPLv2

LIB_DEPENDS=	libvirt.so:devel/libvirt

USES=		gettext gmake gnome libtool meson pathfix pkgconfig \
		python:3.6+ tar:xz

OPTIONS_DEFINE=	DOCS VALA
OPTIONS_DEFAULT=	DOCS VALA
OPTIONS_SUB=	yes
DOCS_MESON_ENABLED=	docs
DOCS_BUILD_DEPENDS=	gtk-doc>=0:textproc/gtk-doc
VALA_DESC=	Vala binding
VALA_MESON_ENABLED=	vapi
VALA_BUILD_DEPENDS=	valac:lang/vala

MESON_ARGS+=	-Dintrospection=enabled
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
