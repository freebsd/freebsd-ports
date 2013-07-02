# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libvirt-glib
PORTVERSION=	0.1.6
CATEGORIES=	devel
MASTER_SITES=	ftp://libvirt.org/libvirt/glib/

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Glib bindings for Libvirt virtualization API

BUILD_DEPENDS=	gio-fam-backend>=0:${PORTSDIR}/devel/gio-fam-backend \
		gobject-introspection>=1.34.2:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	virt.1000:${PORTSDIR}/devel/libvirt

GNU_CONFIGURE=	yes
USES=	pathfix pkgconfig
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -fstack-protector
CONFIGURE_ARGS+=	--enable-introspection

post-patch-script:
	@${REINPLACE_CMD} 's}--quiet}--quiet --libtool=${LIBTOOL}}' \
		${WRKSRC}/libvirt-*/Makefile.in

.include <bsd.port.mk>
