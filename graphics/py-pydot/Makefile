# Created by: Stefan Walter <sw@gegenunendlich.de>
# $FreeBSD$

PORTNAME=	pydot
PORTVERSION=	1.0.28
#PORTREVISION=	0
CATEGORIES=	graphics python
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python interface to the Graphviz Dot language

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/pyparsing.py:${PORTSDIR}/devel/py-parsing
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pyparsing.py:${PORTSDIR}/devel/py-parsing \
		dot:${PORTSDIR}/graphics/graphviz

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
