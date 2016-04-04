# Created by: Hye-Shik Chang <perky@fallin.lv>
# $FreeBSD$

PORTNAME=	pygraphviz
PORTVERSION=	1.3.1
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python interface to GraphViz agraph


LIB_DEPENDS=	libcgraph.so:graphics/graphviz
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0.10.1:devel/py-nose

USES=		pkgconfig python
USE_PYTHON=	autoplist concurrent distutils

PYDISTUTILS_BUILD_TARGET=	build build_ext
PYDISTUTILS_BUILDARGS=		--include-dirs=${LOCALBASE}/include \
				--library-dirs=${LOCALBASE}/lib/graphviz

post-patch:
	@${REINPLACE_CMD} -e 's+%%LOCALBASE%%+${LOCALBASE}+; \
		s+^docdirbase.*=.*+docdirbase = "${DOCSDIR:S/${PREFIX}\///}"+' ${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pygraphviz/_graphviz.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
