# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libvirt-glib
PORTVERSION=	0.1.8
CATEGORIES=	devel
MASTER_SITES=	ftp://libvirt.org/libvirt/glib/

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Glib bindings for Libvirt virtualization API

LIB_DEPENDS=	libvirt.so:${PORTSDIR}/devel/libvirt

GNU_CONFIGURE=	yes
USES=	pathfix pkgconfig gmake
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	intltool introspection
USE_PYTHON=	2
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -fstack-protector
CONFIGURE_ARGS+=	--enable-introspection

SHLIB_VER=	1.0
STRIP_FILES=	libvirt-glib-${SHLIB_VER}.so.1 \
		libvirt-gconfig-${SHLIB_VER}.so.1 \
		libvirt-gobject-${SHLIB_VER}.so.1

post-patch-script:
	@${REINPLACE_CMD} 's}--quiet}--quiet --libtool=${LIBTOOL}}' \
		${WRKSRC}/libvirt-*/Makefile.in

post-install-script:
.for lib in ${STRIP_FILES}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${lib}
.endfor
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${lib}/python${PYTHON_VER}/site-packages/libvirtglibmod.so

.include <bsd.port.mk>
