PORTNAME=	pymemcache
PORTVERSION=	4.0.0
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ale_sagra@hotmail.com
COMMENT=	Comprehensive, fast, pure-Python memcached client
WWW=		https://github.com/pinterest/pymemcache

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=   ${PYTHON_PKGNAMEPREFIX}Faker>0:devel/py-Faker@${PY_FLAVOR} \
                ${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
                ${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
                ${PYTHON_PKGNAMEPREFIX}gevent>0:devel/py-gevent@${PY_FLAVOR} \
                ${PYTHON_PKGNAMEPREFIX}pylibmc>0:databases/py-pylibmc@${PY_FLAVOR} \
                ${PYTHON_PKGNAMEPREFIX}python-memcached>0:databases/py-python-memcached@${PY_FLAVOR} \
                ${PYTHON_PKGNAMEPREFIX}zstd>0:archivers/py-zstd@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -rs -v

.include <bsd.port.mk>
