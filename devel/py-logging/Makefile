# New ports collection makefile for:	py-logging
# Date created:		6 April 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	logging
PORTVERSION=	0.4.7
CATEGORIES=	devel python
MASTER_SITES=	http://www.red-dove.com/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	perky@FreeBSD.org

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/py-logging

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${WRKSRC}/test/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
