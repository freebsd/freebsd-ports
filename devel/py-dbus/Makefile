PORTNAME=	dbus
DISTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	devel gnome python
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus-python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	dbus-python-${DISTVERSION}

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Python bindings for the D-BUS messaging system
WWW=		https://dbus.freedesktop.org/doc/dbus-python/

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygobject>0:devel/py-pygobject@${PY_FLAVOR}

USES=		gettext gmake libtool pathfix pkgconfig python

USE_PYTHON=	flavors

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir=${DOCSDIR} \
		--disable-api-docs
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	DOCS HTMLDOCS EXAMPLES

HTMLDOCS_IMPLIES=		DOCS
HTMLDOCS_DESC=			Build and install HTML documentation (requires Sphinx)
HTMLDOCS_CONFIGURE_ENABLE=	documentation
HTMLDOCS_BUILD_DEPENDS=		sphinx-build:textproc/py-sphinx \
				${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR}

post-patch:
	${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' ${WRKSRC}/test/TestSuitePythonService.service.in

post-patch-DOCS-on:
	@${REINPLACE_CMD} -e 's|HEADERS install-dist_docDATA|HEADERS|g ; \
		s|PYTHON install-nodist_docDATA|PYTHON|g' \
			${WRKSRC}/Makefile.in

post-install:
	@${RM} -r ${STAGEDIR}${DOCSDIR}/_sources

	${MKDIR} ${STAGEDIR}${DOCSDIR} && \
		${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR} && \
		${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}

	${MKDIR} ${STAGEDIR}${EXAMPLESDIR} && \
		${INSTALL_DATA} ${WRKSRC}/examples/*.py ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
