# Created by: Babak Farrokhi <farrokhi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	asyncpg
PORTVERSION=	0.18.2
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	High performance PostgreSQL Client Library for Python/asyncio

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	DOCS

USES=		pgsql:9.2+ python:3.5+
USE_PYTHON=	autoplist concurrent distutils setuptools

PORTDOCS=	PKG-INFO README.rst

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/asyncpg/protocol/protocol.so

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
