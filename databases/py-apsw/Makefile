PORTNAME=	apsw
PORTVERSION=	3.50.3.0
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Another Python SQLite Wrapper
WWW=		https://rogerbinns.github.io/apsw/ \
		https://github.com/rogerbinns/apsw

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		sqlite3>=${PORTVERSION:R:R},1:databases/sqlite3

USES=		localbase python sqlite
USE_PYTHON=	autoplist concurrent pep517 unittest

TEST_ARGS=	discover -s apsw
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

post-patch:
	@${PRINTF} '[build_ext]\nuse_system_sqlite_config = True\n' > ${WRKSRC}/setup.apsw

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
