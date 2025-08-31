PORTNAME=	svglib
DISTVERSION=	1.5.1
PORTREVISION=	3
CATEGORIES=	converters python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Pure-Python library for reading and converting SVG
WWW=		https://github.com/deeplook/svglib

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cssselect2>=0.2.0:textproc/py-cssselect2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml5>0:devel/py-lxml5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}reportlab>0:print/py-reportlab@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tinycss2>=0.6.0:textproc/py-tinycss2@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent distutils pytest
CPE_VENDOR=	svglib_project
PYTEST_IGNORED_TESTS=	test_font_family

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

CONFLICTS_INSTALL=	svg2pdf # bin/svg2pdf

NO_ARCH=	yes

.include <bsd.port.mk>
