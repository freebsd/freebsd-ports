PORTNAME=	gom
PORTVERSION=	0.5.4
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject Data Mapper
WWW=		https://https://gitlab.gnome.org/GNOME/gom

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome meson pkgconfig python sqlite tar:xz
USE_GNOME=	gdkpixbuf glib20 introspection pygobject3

USE_LDCONFIG=	yes
BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
