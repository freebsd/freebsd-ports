# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	pylint
PORTVERSION=	1.1.0
CATEGORIES=	devel python
MASTER_SITES=	LOGILAB
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Analyzes python source code looking for bugs and signs of poor quality

LICENSE=	LGPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astroid>=1.0.0:${PORTSDIR}/devel/py-astroid

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

OPTIONS_DEFINE=	GUI

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUI}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter
.endif

.include <bsd.port.mk>
