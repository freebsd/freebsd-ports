# Created by: Babak Farrokhi <farrokhi@FreeBSD.org>

PORTNAME=	aiopg
PORTVERSION=	1.3.0
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Python library for accessing PostgreSQL database using asyncio

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=2.7.0:databases/py-psycopg2@${PY_FLAVOR}

USES=		pgsql:9.2+ python:3.4+
USE_PYTHON=	autoplist concurrent distutils
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS
PORTDOCS=	PKG-INFO README.rst CHANGES.txt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
