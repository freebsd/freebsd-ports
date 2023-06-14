PORTNAME=	rope
DISTVERSION=	1.7.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jjachuf@gmail.com
COMMENT=	Python refactoring library
WWW=		https://github.com/python-rope/rope

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytoolconfig>=0:devel/py-pytoolconfig@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=4.5.0:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx-autodoc-typehints>0:textproc/py-sphinx-autodoc-typehints@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR}

# 1 failed, 2013 passed, 21 skipped, 5 xfailed, 1809 warnings
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-timeout>=0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytoolconfig>=0:devel/py-pytoolconfig@${PY_FLAVOR}

USES=		cpe python pytest
USE_PYTHON=	autoplist pep517

CPE_VENDOR=	rope_project

NO_ARCH=	yes

.include <bsd.port.mk>
