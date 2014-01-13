# Created by: Mark Linimon <linimon@lonesome.com>
# $FreeBSD$

PORTNAME=	dns
PORTVERSION=	2.3.6
PORTREVISION=	1
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

USE_PYTHON=	2
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pydns

DOCS=		README.txt README-guido.txt
DOCSDIR=	${PREFIX}/share/doc/py-dns

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
