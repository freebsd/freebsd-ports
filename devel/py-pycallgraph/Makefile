PORTNAME=	pycallgraph
PORTVERSION=	1.0.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Python library that creates call graphs for Python programs

LICENSE=	GPLv2

RUN_DEPENDS+=	dot:graphics/graphviz

USES=		python
USE_PYTHON=	distutils autoplist concurrent

PLIST_FILES=	man/man1/pycallgraph.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/pycallgraph.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
