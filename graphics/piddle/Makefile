# Created by: dom@happygiraffe.net
# $FreeBSD$

PORTNAME=	piddle
PORTVERSION=	1.0.15
PORTEPOCH=	1
CATEGORIES=	graphics python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical Drawing library for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PORTDOCS=	*

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.mk>
