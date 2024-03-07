PORTNAME=	glibd
PORTVERSION=	2.4.3
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	D language bindings for the GLib Utility Library
WWW=		https://github.com/gtkd-developers/GlibD

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		https://github.com/gtkd-developers/GlibD/issues/20

BUILD_DEPENDS=	girtod:lang/gir-to-d \
		ldc2:lang/ldc
LIB_DEPENDS=	libphobos2-ldc-shared.so:lang/ldc \
		libdruntime-ldc-shared.so:lang/ldc

USES=		gnome meson pkgconfig

USE_GNOME=	glib20 introspection

USE_GITHUB=	yes
GH_ACCOUNT=	gtkd-developers
GH_PROJECT=	GlibD

.include <bsd.port.mk>
