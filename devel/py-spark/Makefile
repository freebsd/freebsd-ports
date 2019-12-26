# Created by: ijliao
# $FreeBSD$

PORTNAME=	spark
PORTVERSION=	0.6.1
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	http://pages.cpsc.ucalgary.ca/~aycock/spark/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scanning, Parsing, and Rewriting Kit

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

USES=		python:2.7
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/spark.py ${STAGEDIR}${PYTHON_SITELIBDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in doc.html doc.tex paper.ps.gz
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
