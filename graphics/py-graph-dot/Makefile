# New ports collection makefile for:	py-graph
# Date created:		2008-08-29
# Whom:			Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	graph
PORTVERSION=	1.6.1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-graph-${PORTVERSION}

MAINTAINER=	yzlin@cs.nctu.edu.tw
COMMENT=	A library for working with graphs in Python

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pydot>=0:${PORTSDIR}/graphics/py-pydot

PROJECTHOST=	python-graph
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	python_graph

USE_BZIP2=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

TESTFILES=	unittests-accessibility.py \
		unittests-cycles.py \
		unittests-digraph.py \
		unittests-filters.py \
		unittests-graph.py \
		unittests-heuristics.py \
		unittests-readwrite.py \
		unittests-searching.py \
		unittests-sorting.py \

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in COPYING Changelog README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

#  This target is only meant to be used by the port maintainer.
x-regression-test:	install
.for f in ${TESTFILES}
	@${ECHO} "" >> ${WRKSRC}/tests/${f}
	@${ECHO} "if __name__ == '__main__':" >> ${WRKSRC}/tests/${f}
	@${ECHO} "    unittest.main()" >> ${WRKSRC}/tests/${f}
	@${ECHO} "Unit-testing ${f}..."
	@(cd ${WRKSRC}/tests && ${PYTHON_CMD} ${f})
.endfor

.include <bsd.port.mk>
