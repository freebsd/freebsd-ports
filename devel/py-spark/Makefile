# ex:ts=8
# Ports collection makefile for:	spark
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	spark
PORTVERSION=	0.6.1
CATEGORIES=	devel python
MASTER_SITES=	http://pages.cpsc.ucalgary.ca/~aycock/spark/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scanning, Parsing, and Rewriting Kit

USE_PYTHON=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/spark.py ${PYTHON_SITELIBDIR}
.if !defined(PORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in doc.html doc.tex paper.ps.gz
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
