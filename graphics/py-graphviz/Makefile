# Created by: Hye-Shik Chang <perky@fallin.lv>
# $FreeBSD$

PORTNAME=	graphviz
PORTVERSION=	1.3.1
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP \
		http://networkx.lanl.gov/download/pygraphviz/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pygraphviz-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python interface to GraphViz agraph

BUILD_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz
RUN_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz

USES=		pkgconfig python
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	pygraphviz

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's+%%LOCALBASE%%+${LOCALBASE}+; \
		s+^docdirbase.*=.*+docdirbase = "${DOCSDIR:S/${PREFIX}\///}"+' ${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pygraphviz/_graphviz.so

.include <bsd.port.mk>
