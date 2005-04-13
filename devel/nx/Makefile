# ex:ts=8
# Ports collection makefile for:	NetworkX
# Date created:			Apr 13, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	nx
PORTVERSION=	0.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	networkx
DISTNAME=	${PORTNAME:U}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Python package for the networks (graph)

BUILD_DEPENDS=	${PYNUMERIC} \
		${PYTHON_SITELIBDIR}/pygsl/__init__.py:${PORTSDIR}/math/py-gsl \
		ipython:${PORTSDIR}/devel/ipython \
		${PYTHON_SITELIBDIR}/matplotlib/__init__.py:${PORTSDIR}/math/py-matplotlib \
		${PYTHON_SITELIBDIR}/pydot.py:${PORTSDIR}/graphics/py-pydot \
		dot:${PORTSDIR}/graphics/graphviz
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes
DATADIR=	${PREFIX}/share/${PORTNAME:U}

.include <bsd.port.pre.mk>

post-install:
.for d in ${DATADIR} ${PYTHON_SITELIBDIR}/NX
	@${FIND} ${d} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${d} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endfor

.include <bsd.port.post.mk>
