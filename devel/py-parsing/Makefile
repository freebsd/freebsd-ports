# New ports collection makefile for:	py-parsing
# Date created:		1 Jul 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	parsing
PORTVERSION=	1.5.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	SF/pyparsing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyparsing-${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	General parsing module for Python

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pyparsing

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/htmldoc/* ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
