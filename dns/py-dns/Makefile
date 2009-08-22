# New ports collection makefile for:	py-dns
# Date created:				21 September 2002
# Whom:					Mark Linimon (linimon@lonesome.com)
#
# $FreeBSD$
#

PORTNAME=	dns
PORTVERSION=	2.3.3
CATEGORIES=	dns python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/py${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pydns-${PORTVERSION}

MAINTAINER=	linimon@FreeBSD.org
COMMENT=	DNS (Domain Name Service) library for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pydns

DOCS=		README.txt README-guido.txt
DOCSDIR=	${PREFIX}/share/doc/py-dns

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
