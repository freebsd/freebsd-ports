# New ports collection makefile for:	py-parsing
# Date created:		1 Jul 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	parsing
PORTVERSION=	1.3.2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pyparsing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyparsing-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	General parsing module for Python

USE_PYTHON=	2.3+
USE_PYDISTUTILS=yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/htmldoc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
