PORTNAME=	libgusb
DISTVERSION=	0.4.9
CATEGORIES=	devel
MASTER_SITES=	https://github.com/hughsie/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GUsb is a GObject wrapper for libusb1
WWW=		https://github.com/hughsie/libgusb

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PY_SETUPTOOLS}
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib
TEST_DEPENDS=	hwdata>0:misc/hwdata

USES=		gnome meson pkgconfig python:build tar:xz
USE_GNOME=	glib20 introspection:build

OPTIONS_DEFINE=		DOCS VAPI
OPTIONS_DEFAULT=	DOCS VAPI
OPTIONS_SUB=		yes

MESON_ARGS=		-Dumockdev=disabled \
			-Dusb_ids=${LOCALBASE}/share/hwdata/hwdata/usb.ids

DOCS_BUILD_DEPENDS=	gtk-doc>0:textproc/gtk-doc \
			${PYTHON_PKGNAMEPREFIX}gi-docgen>=0:textproc/py-gi-docgen@${PY_FLAVOR}
DOCS_MESON_TRUE=	docs

VAPI_USES=		vala:build
VAPI_MESON_TRUE=	vapi

.include <bsd.port.mk>
