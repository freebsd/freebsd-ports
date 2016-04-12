# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	pycallgraph
PORTVERSION=	0.5.1
PORTREVISION=	4
CATEGORIES=	devel python
MASTER_SITES=	http://pycallgraph.slowchop.com/files/download/ \
		http://www.cs.nctu.edu.tw/~lwhsu/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Python library that creates call graphs for Python programs

LICENSE=	GPLv2

RUN_DEPENDS+=	dot:graphics/graphviz

USES=		python
USE_PYTHON=	distutils

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

OPTIONS_DEFINE=	EXAMPLES


post-install:
	${INSTALL_MAN} ${WRKSRC}/man/pycallgraph.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_BIN} \* ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
