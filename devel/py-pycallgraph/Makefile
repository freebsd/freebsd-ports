# New ports collection makefile for:	py-pycallgraph
# Date created:		Feb. 09, 2007
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	pycallgraph
PORTVERSION=	0.3.0
CATEGORIES=	devel python
MASTER_SITES=	http://pycallgraph.slowchop.com/files/download/ \
		http://www.cs.nctu.edu.tw/~lwhsu/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	A Python library that creates call graphs for Python programs

RUN_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
