# New ports collection makefile for:	py-graph
# Date created:		2008-08-29
# Whom:			Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	graph-dot
PORTVERSION=	1.7.0
CATEGORIES=	graphics python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	yzlin@FreeBSD.org
COMMENT=	A library for working with graphs in Python, dot module

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pydot>=0:${PORTSDIR}/graphics/py-pydot \
		${PYTHON_PKGNAMEPREFIX}graph-core>=${PORTVERSION}:${PORTSDIR}/graphics/py-graph-core

PROJECTHOST=	python-graph
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	python_graph_dot

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
