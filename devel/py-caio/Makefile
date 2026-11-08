PORTNAME=	caio
PORTVERSION=	0.12.9
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Asynchronous file IO for Python
WWW=		https://github.com/mosquito/caio/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiomisc-pytest>0:devel/py-aiomisc-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV}
TEST_ARGS=	--asyncio-mode=auto -p no:aiomisc -p no:relaxed # aiomisc-based tests fail, see https://github.com/mosquito/caio/issues/67

# tests as of 0.12.9: 41 passed 164 skipped

.include <bsd.port.mk>
