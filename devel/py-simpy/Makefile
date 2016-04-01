# Created by: ijliao
# $FreeBSD$

PORTNAME=	simpy
PORTVERSION=	3.0.8
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Simulation in Python

LICENSE=	LGPL21

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	TKINTER DOCS
TKINTER_DESC=	py-tkinter for plot

PORTDOCS=	*

TKINTER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
