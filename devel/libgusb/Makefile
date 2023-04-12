PORTNAME=	libgusb
PORTVERSION=	0.3.10
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GUsb is a GObject wrapper for libusb1
WWW=		https://github.com/hughsie/libgusb

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR}

USES=		gnome meson pkgconfig python:build

USE_GITHUB=	yes
GH_ACCOUNT=	hughsie

USE_GNOME=	glib20 introspection:build

OPTIONS_DEFINE=		DOCS VAPI
OPTIONS_DEFAULT=	DOCS VAPI
OPTIONS_SUB=		yes

DOCS_BUILD_DEPENDS=	gtk-doc>0:textproc/gtk-doc
DOCS_MESON_TRUE=	docs

VAPI_MESON_TRUE=	vapi
VAPI_USES=		vala:build

.include <bsd.port.mk>
