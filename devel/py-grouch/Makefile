# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	grouch
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	https://www.mems-exchange.org/software/files/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Grouch-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System for describing and enforcing a Python object schema

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		python:2.7
USE_PYTHON=	distutils autoplist

PORTDOCS=	*
PORTEXAMPLES=	*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docfile in CHANGES README
	${INSTALL_DATA} ${WRKSRC}/${docfile}.txt ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}
post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
