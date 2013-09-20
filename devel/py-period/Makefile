# Created by: ijliao
# $FreeBSD$

PORTNAME=	period
PORTVERSION=	0.5
CATEGORIES=	devel python
MASTER_SITES=	http://www.biostat.wisc.edu/~annis/creations/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A basic time period checking library

USE_PYTHON=	yes
NO_BUILD=	yes

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/period.py ${PYTHON_SITELIBDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for ex in html txt
	${INSTALL_DATA} ${WRKSRC}/period.${ex} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
