# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	psycopg2
PORTVERSION=	2.7.3.2
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP \
		http://initd.org/psycopg/tarballs/PSYCOPG-${PORTVERSION:R:S|.|-|}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	High performance Python adapter for PostgreSQL

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/doc/COPYING.LESSER

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_PYTHON=	autoplist concurrent distutils
USES=		pgsql python

PORTDOCS=	AUTHORS INSTALL NEWS PKG-INFO README.rst
PORTEXAMPLES=	*

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/psycopg2/_psycopg.so

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
