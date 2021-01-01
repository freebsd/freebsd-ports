# Created by: Mark Linimon <linimon@lonesome.com>
# $FreeBSD$

PORTNAME=	dns
PORTVERSION=	2.3.6
PORTREVISION=	2
CATEGORIES=	dns python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/py${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pydns-${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	DNS (Domain Name Service) library for Python

LICENSE=	CNRI
LICENSE_NAME=	CNRI LICENSE AGREEMENT
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		python:2.7
USE_PYTHON=	distutils autoplist

PORTDOCS=	README.txt README-guido.txt
DOCSDIR=	${PREFIX}/share/doc/py-dns

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
