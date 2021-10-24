# Created by: Rainer Hurling <rhurlin@gwdg.de>

PORTNAME=	qstylizer
PORTVERSION=	0.2.1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Qt Stylesheet Generator for PyQt/PySide

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}inflection>=0.3.1,<1:devel/py-inflection@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tinycss2>=0.5,<2:textproc/py-tinycss2@${PY_FLAVOR}
# pytest-catchlog >=1,<2 does not exist until now :(
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=0:devel/py-virtualenv@${PY_FLAVOR}

USES=		pyqt:5 python:3.7+
# PyPi only has the wheel version
USE_GITHUB=	yes
GH_ACCOUNT=	blambright

USE_PYQT=	pyqt5
USE_PYTHON=	autoplist distutils

MAKE_ENV=	PBR_VERSION=${PORTVERSION}

NO_ARCH=	yes

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinxcontrib-autoprogram>0:textproc/py-sphinxcontrib-autoprogram@${PY_FLAVOR}
DOCS_USES=	gmake

post-patch:
	@${REINPLACE_CMD} -e 's|python -msphinx|${PYTHON_VERSION} -msphinx|g' \
		${WRKSRC}/doc/Makefile

do-build-DOCS-on:
	(cd ${WRKSRC}/doc && ${GMAKE} html)

post-build-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/_build/html/ && ${CP} -R api *.html *.js ${STAGEDIR}${DOCSDIR})

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -rs -v

.include <bsd.port.mk>
