# Created by: Daniel Bretoi
# $FreeBSD$

PORTNAME=	utils
PORTVERSION=	0.4.0
CATEGORIES=	devel python
MASTER_SITES=	http://www.voidspace.org.uk/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pythonutils-${PORTVERSION}

MAINTAINER=	daniel@netwalk.org
COMMENT=	General utility modules that simplify common programming in Python

USES=		python:2.7 zip
USE_PYTHON=	distutils autoplist

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
