# Created by: ijliao
# $FreeBSD$

PORTNAME=	log4py
PORTVERSION=	1.3
CATEGORIES=	devel python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xride@FreeBSD.org
COMMENT=	A python logging module

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.if !defined(NOPORTDOCS)
NO_STAGE=	yes
post-install:
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
