# New ports collection makefile for:	py-pmock
# Date created:		2005-01-13
# Whom:			Piet Delport <pjd@satori.za.net>
#
# $FreeBSD$

PORTNAME=	pmock
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mock object library for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

CPIOFLAGS=	--quiet -pdm -R ${SHAREOWN}:${SHAREGRP}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${FIND} . | ${CPIO} ${CPIOFLAGS} ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${FIND} . | ${CPIO} ${CPIOFLAGS} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
