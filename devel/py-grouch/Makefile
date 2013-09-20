# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	grouch
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	https://www.mems-exchange.org/software/files/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Grouch-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A system for describing and enforcing a Python object schema

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Grouch

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in CHANGES LICENSE README
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile}.txt ${DOCSDIR}
.endfor
	@ ${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@ ${MKDIR} ${EXAMPLESDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
