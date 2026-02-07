PORTNAME=	svglib
DISTVERSION=	1.6.0
CATEGORIES=	converters python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Pure-Python library for reading and converting SVG
WWW=		https://github.com/deeplook/svglib

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cssselect2>=0.2.0:textproc/py-cssselect2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=6.0.0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}reportlab>=4.4.3:print/py-reportlab@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rlpycairo>=0.4.0:graphics/py-rlpycairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tinycss2>=0.6.0:textproc/py-tinycss2@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent pep517 pytest
CPE_VENDOR=	svglib_project
# test_font_family leads to assertion errors
PYTEST_IGNORED_TESTS=	test_font_family

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

CONFLICTS_INSTALL=	svg2pdf # bin/svg2pdf

NO_ARCH=	yes

.include <bsd.port.mk>
