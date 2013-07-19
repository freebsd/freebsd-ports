# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	parsing
PORTVERSION=	2.0.1
CATEGORIES=	devel python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/py${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyparsing-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	General parsing module for Python

USE_PYTHON=	yes
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
