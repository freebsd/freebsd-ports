# Ports collection Makefile for:	kjbuckets
# Date created:				03/27/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		kjbuckets
PORTVERSION=		1.0.0
PORTEPOCH=		1
CATEGORIES=		devel python
MASTER_SITES=		SF/gadfly/gadfly/${PORTVERSION}
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		gadfly-${PORTVERSION}

MAINTAINER=		ports@FreeBSD.org
COMMENT=	Graph and set datatypes for Python (C extension)

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGVERSION=	2.2
WRKSRC=			${WRKDIR}/${DISTNAME}/kjbuckets

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../COPYRIGHT.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../doc/kjbuckets.txt ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/../doc/demo/kjbuckets/*.py ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
