# Created by: Hye-Shik Chang <perky@fallin.lv>
# $FreeBSD$

PORTNAME=	graphviz
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP \
		http://networkx.lanl.gov/download/pygraphviz/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pygraphviz-${PORTVERSION}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Python interface to GraphViz agraph

BUILD_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz
RUN_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	pygraphviz

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's+%%LOCALBASE%%+${LOCALBASE}+; \
		s+^docdirbase.*=.*+docdirbase = "${DOCSDIR:S/${PREFIX}\///}"+' ${WRKSRC}/setup.py

.include <bsd.port.mk>
