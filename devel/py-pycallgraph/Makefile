# New ports collection makefile for:	py-pycallgraph
# Date created:		Feb. 09, 2007
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	pycallgraph
PORTVERSION=	0.5.1
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	http://pycallgraph.slowchop.com/files/download/ \
		http://www.cs.nctu.edu.tw/~lwhsu/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	A Python library that creates call graphs for Python programs

RUN_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.if !defined(NO_INSTALL_MANPAGES)
MAN1=	pycallgraph.1
.endif

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

post-install:
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/man/pycallgraph.1 ${MAN1PREFIX}/man/man1
.endif

.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_BIN} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
