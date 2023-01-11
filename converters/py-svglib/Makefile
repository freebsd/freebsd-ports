PORTNAME=	svglib
DISTVERSION=	1.4.1
CATEGORIES=	converters python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Pure-Python library for reading and converting SVG
WWW=		https://github.com/deeplook/svglib

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cssselect2>=0.2.0:textproc/py-cssselect2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}reportlab>0:print/py-reportlab@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tinycss2>=0.6.0:textproc/py-tinycss2@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		cpe python:3.7+
USE_PYTHON=	autoplist concurrent distutils
CPE_VENDOR=	svglib_project

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

CONFLICTS_INSTALL=	svg2pdf # bin/svg2pdf

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs -k 'not test_font_family'

.include <bsd.port.mk>
