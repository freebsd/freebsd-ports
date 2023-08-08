PORTNAME=	asyncpg
PORTVERSION=	0.27.0
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	High performance PostgreSQL Client Library for Python/asyncio
WWW=		https://github.com/MagicStack/asyncpg/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe pgsql:11+ python
CPE_VENDOR=	magic
USE_PYTHON=	autoplist concurrent cython distutils

OPTIONS_DEFINE=	DOCS
PORTDOCS=	PKG-INFO README.rst

post-extract:
	@${RM} ${WRKSRC}/asyncpg/pgproto/*.c
	@${RM} ${WRKSRC}/asyncpg/protocol/*.c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/asyncpg/protocol/protocol*.so
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/asyncpg/pgproto/pgproto*.so

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
