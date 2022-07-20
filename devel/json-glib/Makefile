PORTNAME=	json-glib
PORTVERSION=	1.6.6
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	JSON (RFC 4627) interface for Glib

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext gnome localbase meson python:3.7+ pkgconfig tar:xz
USE_GNOME=	glib20
USE_LDCONFIG=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	GIR DOCS
OPTIONS_DEFAULT=GIR
OPTIONS_SUB=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD}

DOCS_BUILD_DEPENDS=	\
			${PYTHON_PKGNAMEPREFIX}gi-docgen>=0:textproc/py-gi-docgen@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}markdown>0:textproc/py-markdown@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}markupsafe>0:textproc/py-markupsafe@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}smartypants>0:textproc/py-smartypants@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}toml>0:textproc/py-toml@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}typogrify>0:textproc/py-typogrify@${PY_FLAVOR}
DOCS_MESON_ENABLED=	gtk_doc
GIR_DESC=	Build introspection data
GIR_USE=	gnome=introspection
GIR_MESON_ENABLED=	introspection

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/libexec/installed-tests
	@${RM} -r ${STAGEDIR}${PREFIX}/share/installed-tests

.include <bsd.port.mk>
