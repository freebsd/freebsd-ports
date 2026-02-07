PORTNAME=	filemagic
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python API for libmagic, the library behind the Unix file command
WWW=		https://filemagic.readthedocs.io/en/latest/ \
		https://github.com/aliles/filemagic

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

do-test:
	${MKDIR} ${WRKSRC}/tests/magic
	${FETCH_CMD} -o ${WRKSRC}/tests/magic/python https://github.com/aliles/filemagic/raw/master/tests/magic/python
	cd ${WRKSRC} && ${SETENV} PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR} ${PYTHON_CMD} tests/test_magic.py

.include <bsd.port.mk>
