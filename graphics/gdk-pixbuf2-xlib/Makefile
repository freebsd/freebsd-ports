PORTNAME=	gdk-pixbuf-xlib
PORTVERSION=	2.40.2
CATEGORIES=	graphics
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	deprecated API for integrating Xlib and GdkPixbuf

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl

USES=		cpe gettext gnome localbase:ldflags meson pkgconfig \
		python:3.7+,build shared-mime-info tar:xz trigger xorg
CPE_VENDOR=	gnome
USE_GNOME=	glib20 introspection:build libxslt:build gdkpixbuf2
USE_XORG=	x11
USE_LDCONFIG=	yes
TRIGGERS=	gdk-pixbuf-query-loaders-xlib
SUB_LIST=	GTK2_VERSION=${GTK2_VERSION}

BINARY_ALIAS=	python3=${PYTHON_VERSION}

.include <bsd.port.mk>
