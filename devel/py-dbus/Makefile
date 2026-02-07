PORTNAME=	dbus
DISTVERSION=	1.4.0
CATEGORIES=	devel gnome python
MASTER_SITES=	https://dbus.freedesktop.org/releases/dbus-python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	dbus-python-${DISTVERSION}

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Python bindings for the D-BUS messaging system
WWW=		https://gitlab.freedesktop.org/dbus/dbus-python

LICENSE=	MIT

LIB_DEPENDS=	libdbus-1.so:devel/dbus
TEST_DEPENDS=	bash:shells/bash

USES=		gnome meson pkgconfig python shebangfix tar:xz
USE_GNOME=	glib20 pygobject3
USE_PYTHON=	flavors
SHEBANG_FILES=	test/run-test.sh \
		test/*.py

MESON_ARGS=	-Dtests=enabled \
		-Dpython.bytecompile=1

DOCSDIR=	${PREFIX}/share/doc/dbus-python
EXAMPLESDIR=	${PREFIX}/share/examples/dbus-python

BINARY_ALIAS=	python3=${PYTHON_CMD}

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes

DOCS_DESC=			Build and install HTML documentation (requires Sphinx)
DOCS_BUILD_DEPENDS=		sphinx-build:textproc/py-sphinx \
				${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR}
DOCS_MESON_ENABLED=		doc

post-patch:
	${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' ${WRKSRC}/test/TestSuitePythonService.service.in

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR} && \
		${INSTALL_DATA} ${WRKSRC}/examples/*.py ${STAGEDIR}${EXAMPLESDIR}

post-install-DOCS-on:
	@${RM} -Rf ${STAGEDIR}${DOCSDIR}/html/.doctrees/
	@${RM} -Rf ${STAGEDIR}${DOCSDIR}/html/_sources/
	@${RM} ${STAGEDIR}${DOCSDIR}/html/.buildinfo

.include <bsd.port.mk>
