PORTNAME=	posix_ipc
DISTVERSION=	1.3.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	POSIX IPC primitives for Python
WWW=		https://semanchuk.com/philip/posix_ipc/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

post-install:
	${STRIP_CMD} ${STAGEDIR}/${PYTHONPREFIX_SITELIBDIR}/posix_ipc*.so

# requires mqueuefs and sem kernel modules loaded

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
