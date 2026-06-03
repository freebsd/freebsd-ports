PORTNAME=	pyserial-asyncio-fast
DISTVERSION=	0.16
CATEGORIES=	comms python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	samm@freebsd.org
COMMENT=	Async I/O extension package for the Python Serial Port Extension
WWW=		https://github.com/home-assistant-libs/pyserial-asyncio-fast

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyserial>=3.1.1:comms/py-pyserial@${PY_FLAVOR}

USES=		python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	home-assistant-libs
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

do-test:
	${SETENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
	    ${PYTHON_CMD} ${WRKSRC}/test/test_asyncio.py

.include <bsd.port.mk>
