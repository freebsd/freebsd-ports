PORTNAME=	asyncpg
PORTVERSION=	0.32.0
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	High performance PostgreSQL Client Library for Python/asyncio
WWW=		https://github.com/MagicStack/asyncpg/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=24.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		cpe pgsql:11+ python
CPE_VENDOR=	magic
USE_PYTHON=	autoplist concurrent cython pep517

PORTDOCS=	PKG-INFO README.rst

OPTIONS_DEFINE=	DOCS

post-extract:
	@${RM} ${WRKSRC}/asyncpg/pgproto/*.c
	@${RM} ${WRKSRC}/asyncpg/protocol/*.c

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/asyncpg -name '*.so' \
		-exec ${STRIP_CMD} {} +

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
