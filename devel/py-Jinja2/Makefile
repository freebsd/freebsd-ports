PORTNAME=	Jinja2
DISTVERSION=	3.1.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX?=
DISTNAME=	${PYWHEEL_NAME}-${DISTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Fast and easy to use stand-alone template engine
WWW=		https://jinja.palletsprojects.com/en/3.1.x/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.9.0:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markupsafe>=2.0.0:textproc/py-markupsafe@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markupsafe>=2.0.0:textproc/py-markupsafe@${PY_FLAVOR}

.if empty(PKGNAMESUFFIX)
USES=		cpe python
CPE_VENDOR=	pocoo
USE_PYTHON=	autoplist pep517 pytest # 23 tests fail, see https://github.com/pallets/jinja/issues/1757
PEP517_INSTALL_CMD=	${PYTHON_CMD} -m installer --destdir ${STAGEDIR} \
			--prefix ${PREFIX} \
			${BUILD_WRKSRC}/dist/${PYWHEEL_NAME}-${DISTVERSION}*.whl
.endif
.if ${PKGNAMESUFFIX} == -doc
USES=		gmake python
USE_PYTHON=	flavors
.endif
PYWHEEL_NAME=	${PORTNAME:tl:C|[-_]+|_|g}

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

NO_ARCH=	yes

OPTIONS_DEFINE?=	BABEL EXAMPLES
OPTIONS_DEFAULT?=	BABEL
BABEL_DESC=		Enable Babel extension

BABEL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=2.7:devel/py-babel@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if empty(PKGNAMESUFFIX)
do-install:
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	@cd ${INSTALL_WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${PEP517_INSTALL_CMD}
	@${PYTHON_CMD} -B ${PORTSDIR}/Mk/Scripts/strip_RECORD.py \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PYWHEEL_NAME}-${DISTVERSION}*.dist-info/RECORD >> ${_PYTHONPKGLIST}
	@${REINPLACE_CMD} \
		-e '/\.pyc$$/d' \
		-e 's|^|${PYTHONPREFIX_SITELIBDIR}/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../etc/|etc/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../bin/|bin/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../include/|include/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../lib/|lib/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../libdata/|libdata/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../libexec/|libexec/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../man/|man/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../sbin/|sbin/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../share/|share/|' \
			${_PYTHONPKGLIST}
	@cd ${STAGEDIR}${PREFIX} && ${FIND} lib -name '*.pyc' >> ${_PYTHONPKGLIST}
.endif

.if ${PKGNAMESUFFIX} == "-doc"
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=0.23:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Pallets-Sphinx-Themes>=2.0.2:textproc/py-pallets-sphinx-themes@${PY_FLAVOR} \
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
	${PYTHON_CMD} -m compileall ${WRKSRC}/docs/examples ; \
	${PYTHON_CMD} -O -m compileall ${WRKSRC}/docs/examples

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/docs/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
.endif

check regression-test: build
.if empty(PKGNAMESUFFIX)
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test
.else
	@${DO_NADA}
.endif

.include <bsd.port.post.mk>
