# ex:ts=8
# Ports collection makefile for:	py-dot
# Date created:		Apr 12, 2005
# Whom:	      		ijliao
#
# $FreeBSD$
#

PORTNAME=	dot
PORTVERSION=	0.9.10
CATEGORIES=	graphics python
MASTER_SITES=	http://www.dkbza.org/data/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pydot-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Python interface to Graphviz's Dot language

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pyparsing.py:${PORTSDIR}/devel/py-parsing \
		dot:${PORTSDIR}/graphics/graphviz

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
