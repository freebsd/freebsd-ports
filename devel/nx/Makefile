# ex:ts=8
# Ports collection makefile for:	NetworkX
# Date created:			Apr 13, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	nx
PORTVERSION=	0.33
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	https://networkx.lanl.gov/download/
DISTNAME=	networkx-${PORTVERSION}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Python package for studying network structure, dynamics, and function

BUILD_DEPENDS=	${PYNUMERIC} \
		${PYTHON_SITELIBDIR}/pygsl/__init__.py:${PORTSDIR}/math/py-gsl \
		ipython:${PORTSDIR}/devel/ipython \
		${PYTHON_SITELIBDIR}/matplotlib/__init__.py:${PORTSDIR}/math/py-matplotlib \
		${PYTHON_SITELIBDIR}/pydot.py:${PORTSDIR}/graphics/py-pydot \
		dot:${PORTSDIR}/graphics/graphviz
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	networkx
PORTDOCS=	*

.include <bsd.port.pre.mk>

post-install:
.for d in ${PYTHON_SITELIBDIR}/networkx
	@${FIND} ${d} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${d} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endfor
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
