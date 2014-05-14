# Created by: ijliao
# $FreeBSD$

PORTNAME=	log4py
PORTVERSION=	1.3
CATEGORIES=	devel python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Python logging module

LICENSE=	MIT

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
