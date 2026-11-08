PORTNAME=	unicorn
PORTVERSION=	2.1.4
CATEGORIES=	emulators python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python bindings for Unicorn CPU emulator framework
WWW=		https://www.unicorn-engine.org/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${LOCALBASE}/lib/libunicorn.so:emulators/unicorn
RUN_DEPENDS=	${LOCALBASE}/lib/libunicorn.so:emulators/unicorn

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes
MAKE_ENV=	LIBUNICORN_PATH=${LOCALBASE}/lib/libunicorn.so
TEST_WRKSRC=	${WRKSRC}/tests

do-test:
	@(cd ${TEST_WRKSRC}; for t in test_*.py; do \
		${SETENV} ${TEST_ENV} ${PYTHON_CMD} $${t}; \
	done)

.include <bsd.port.mk>
