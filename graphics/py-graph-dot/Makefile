# Created by: Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	graph-dot
PORTVERSION=	1.8.2
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Library for working with graphs in Python, dot module

BROKEN=		Unfetchable (google code has gone away)

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pydot>=0:graphics/py-pydot \
		${PYTHON_PKGNAMEPREFIX}graph-core>=${PORTVERSION}:graphics/py-graph-core

PROJECTHOST=	python-graph
USES=		python
USE_PYTHON=	distutils autoplist

# post-install and add-plist-post should not act as reference on how to fix
# egg-based conflicts.
# https://code.google.com/p/python-graph/issues/detail?id=121 contains the
# report for this issue.
post-install:
.for suffix in py pyc pyo
	rm ${STAGEDIR}${PYTHON_SITELIBDIR}/pygraph/readwrite/__init__.${suffix}
.endfor

add-plist-post:
	@${REINPLACE_CMD} -e "/readwrite\/__init__.py/d" ${TMPPLIST}

.include <bsd.port.mk>
