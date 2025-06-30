PORTNAME=	libvirt-glib
PORTVERSION=	5.0.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://download.libvirt.org/glib/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Glib bindings for Libvirt virtualization API
WWW=		https://www.libvirt.org

LICENSE=	GPLv2

LIB_DEPENDS=	libvirt.so:devel/libvirt

USES=		gettext gmake gnome meson pathfix pkgconfig \
		python tar:xz

OPTIONS_DEFINE=	DOCS VAPI
OPTIONS_DEFAULT=	DOCS VAPI
OPTIONS_SUB=	yes
DOCS_MESON_ENABLED=	docs
DOCS_BUILD_DEPENDS=	gtk-doc>=0:textproc/gtk-doc
VAPI_MESON_ENABLED=	vapi
VAPI_USES=		vala:build

MESON_ARGS+=	-Dintrospection=enabled -Dgit_werror=disabled
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
