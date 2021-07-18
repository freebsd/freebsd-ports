# Created by: Nicola Vitale <nivit@FreeBSD.org>

PORTNAME=	Jinja2
PORTVERSION=	2.11.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX?=

MAINTAINER=	nivit@FreeBSD.org
COMMENT?=	Fast and easy to use stand-alone template engine

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markupsafe>=0.23:textproc/py-markupsafe@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markupsafe>=0.23:textproc/py-markupsafe@${PY_FLAVOR}

NO_ARCH=	yes
.if empty(PKGNAMESUFFIX)
USES=		python:2.7+
USE_PYTHON=	autoplist distutils
.endif
.if ${PKGNAMESUFFIX} == -doc
USES=		gmake python:3.6+
USE_PYTHON=	flavors
.endif

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE?=	BABEL EXAMPLES
OPTIONS_DEFAULT?=	BABEL
BABEL_DESC=		Enable Babel extension

BABEL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=1.3:devel/py-babel@${PY_FLAVOR}

PY2TO3_CMD=	${LOCALBASE}/bin/2to3-${PYTHON_VER}
PY2TO3_ARGS=	--fix=all --no-diffs --nobackups --verbose --write

.include <bsd.port.pre.mk>

.if ${PKGNAMESUFFIX} == "-doc"
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Pallets-Sphinx-Themes>=1.2.3:textproc/py-pallets-sphinx-themes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>=0.23:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx-issues>=1.2.0:textproc/py-sphinx-issues@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=1.1.3:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-log-cabinet>=1.0.1:textproc/py-sphinxcontrib-log-cabinet@${PY_FLAVOR}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
PORTDOCS=	*
PORT_OPTIONS:=	${PORT_OPTIONS:NEXAMPLES}

do-build:
	(cd ${WRKSRC}/docs && ${MAKE_CMD} SPHINXBUILD=sphinx-build-${PYTHON_VER} html)

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/_build/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
		"! -name .buildinfo")
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
PORTEXAMPLES=	*
post-build:
.	if ${PYTHON_REL} >= 30000
	${PY2TO3_CMD} ${PY2TO3_ARGS} ${WRKSRC}/examples
.	endif
	${PYTHON_CMD} -m compileall ${WRKSRC}/examples ; \
	${PYTHON_CMD} -O -m compileall ${WRKSRC}/examples

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
.endif

check regression-test test: build
.if empty(PKGNAMESUFFIX)
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test
.else
	@${DO_NADA}
.endif

.include <bsd.port.post.mk>
