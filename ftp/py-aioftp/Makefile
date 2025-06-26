PORTNAME=	aioftp
PORTVERSION=	0.26.1
CATEGORIES=	ftp python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	FTP client/server for asyncio
WWW=		https://pypi.org/project/aioftp/ \
		https://aioftp.readthedocs.io/ \
		https://github.com/aio-libs/aioftp

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}siosocks>=0:net/py-siosocks@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trustme>=0:security/py-trustme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}async_timeout>0:devel/py-async_timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>0:dns/py-idna@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest
NO_ARCH=	yes

.include <bsd.port.mk>
