# Created by: ijliao
# $FreeBSD$

PORTNAME=	spark
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://pages.cpsc.ucalgary.ca/~aycock/spark/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scanning, Parsing, and Rewriting Kit

USE_PYTHON=	yes
NO_BUILD=	yes

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/spark.py ${PYTHON_SITELIBDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in doc.html doc.tex paper.ps.gz
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
