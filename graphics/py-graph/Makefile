# New ports collection makefile for:	py-graph
# Date created:		2008-08-29
# Whom:			Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	graph
PORTVERSION=	1.7.0
CATEGORIES=	graphics python
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yzlin@FreeBSD.org
COMMENT=	A library for working with graphs in Python

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}graph-core>=${PORTVERSION}:${PORTSDIR}/graphics/py-graph-core \
		${PYTHON_PKGNAMEPREFIX}graph-dot>=${PORTVERSION}:${PORTSDIR}/graphics/py-graph-dot

USE_PYTHON=	yes

NO_BUILD=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
