# ex:ts=8
# New ports collection makefile for:	py-period
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	period
PORTVERSION=	0.5
CATEGORIES=	devel python
MASTER_SITES=	http://www.biostat.wisc.edu/~annis/creations/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A basic time period checking libary

USE_PYTHON=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/period.py ${PYTHON_SITELIBDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for ex in html txt
	${INSTALL_DATA} ${WRKSRC}/period.${ex} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
