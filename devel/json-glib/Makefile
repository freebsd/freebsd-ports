PORTNAME=	json-glib
DISTVERSION=	1.10.8
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	JSON (RFC 4627) interface for Glib
WWW=		https://live.gnome.org/JsonGlib

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome localbase meson python pkgconfig tar:xz
USE_GNOME=	glib20
USE_LDCONFIG=	yes
MESON_ARGS=	-Dinstalled_tests=false

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS GIR MANPAGES NLS
OPTIONS_DEFAULT=GIR
OPTIONS_SUB=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD}

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gi-docgen>=0:textproc/py-gi-docgen@${PY_FLAVOR} \
			rst2html5:textproc/py-docutils@${PY_FLAVOR}
DOCS_MESON_ENABLED=	documentation
DOCS_IMPLIES=	GIR
GIR_DESC=	Build introspection data
GIR_USE=	gnome=introspection
GIR_MESON_ENABLED=	introspection
MANPAGES_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
			rst2man:textproc/py-docutils@${PY_FLAVOR}
MANPAGES_MESON_TRUE=	man
NLS_USES=	gettext-tools
NLS_MESON_ENABLED=	nls

.include <bsd.port.mk>
