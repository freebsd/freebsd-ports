PORTNAME=	pyserial-asyncio
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6
CATEGORIES=	comms python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	chris@chrullrich.net
COMMENT=	Async I/O support for pyserial
WWW=		https://github.com/pyserial/pyserial-asyncio

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyserial>=3.1.1:comms/py-pyserial@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent distutils
USE_GITHUB=	yes
GH_ACCOUNT=	pyserial

NO_ARCH=	yes

do-test:
	${SETENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
	    ${PYTHON_CMD} ${WRKSRC}/test/test_asyncio.py

.include <bsd.port.mk>
