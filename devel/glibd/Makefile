PORTNAME=	glibd
PORTVERSION=	2.4.4.g
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	D language bindings for the GLib Utility Library
WWW=		https://github.com/gtkd-developers/GlibD

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	girtod:lang/gir-to-d \
		ldc2:lang/ldc
LIB_DEPENDS=	libphobos2-ldc-shared.so:lang/ldc \
		libdruntime-ldc-shared.so:lang/ldc

USES=		gnome meson pkgconfig

USE_GNOME=	glib20 introspection

USE_GITHUB=	yes
GH_ACCOUNT=	gtkd-developers
GH_PROJECT=	GlibD
GH_TAGNAME=	9c37e2e1012b67bc06c46fa742f9bb4190937e81

PIE_UNSAFE=	yes

.include <bsd.port.mk>
