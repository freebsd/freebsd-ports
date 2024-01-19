PORTNAME=	pycallgraph
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Python library that creates call graphs for Python programs
WWW=		https://pycallgraph.slowchop.com/

LICENSE=	GPLv2

RUN_DEPENDS+=	dot:graphics/graphviz

USES=		python
USE_PYTHON=	distutils autoplist concurrent

PLIST_FILES=	share/man/man1/pycallgraph.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/pycallgraph.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
