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
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gadfly
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		gadfly-${PORTVERSION}

MAINTAINER=		tg@FreeBSD.org
COMMENT=	Graph and set datatypes for Python (C extension)

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
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
