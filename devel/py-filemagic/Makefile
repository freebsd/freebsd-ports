PORTNAME=	filemagic
PORTVERSION=	1.6
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python API for libmagic, the library behind the Unix file command

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	${MKDIR} ${WRKSRC}/tests/magic
	${FETCH_CMD} -o ${WRKSRC}/tests/magic/python https://github.com/aliles/filemagic/raw/master/tests/magic/python
	cd ${WRKSRC} && ${SETENV} PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR} ${PYTHON_CMD} tests/test_magic.py

.include <bsd.port.mk>
